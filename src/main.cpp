#include "Shape.h"
#include <math.h>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Trigonometry Is Fun!", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	float r = 250.0f;

	Shape pentagon(window.getSize().x / 2, window.getSize().y / 2, 100, 10.0f);

	sf::View view = window.getDefaultView();

	float a =  2 * acos(0.0f) / 4 ;
	
	float aVel = 0.0f;
	float aAcc = 0.001f;

	view.setCenter(0.0f, 0.0f);
	window.setView(view);

	int frameCount = 0;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		float x = r * cos(a);
		float y = r * sin(a);

		a += aVel;
		aVel += aAcc;

		if(aVel >= 1)
		{
			aVel = 0.001f;
		}

		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
			sf::Vertex(sf::Vector2f(x, y))
		};

		pentagon.m_shape->setPosition(x, y);

		window.clear();

		window.draw(*pentagon.m_shape);
		window.draw(line, 2, sf::Lines);

		window.display();

	}
	
	return 0;
}