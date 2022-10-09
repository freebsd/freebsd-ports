# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.rst', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRES = [
    'Flask>=2.2',
    'SQLAlchemy>=1.4.18',
]

setup_kwargs = {
    'name': 'Flask-SQLAlchemy',
    'version': '%%PORTVERSION%%',
    'description': 'Add SQLAlchemy support to your Flask application.',
    'long_description': long_description,
    'license': 'BSD-3-Clause',
    'author': '',
    'author_email': 'Armin Ronacher <armin.ronacher@active-4.com>',
    'maintainer': '',
    'maintainer_email': 'Pallets <contact@palletsprojects.com>',
    'url': '',
    'packages': [
        'flask_sqlalchemy',
    ],
    'package_dir': {'': 'src'},
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/x-rst',
    'classifiers': [
        'Development Status :: 5 - Production/Stable',
        'Environment :: Web Environment',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
    ],
    'install_requires': INSTALL_REQUIRES,
    'python_requires': '>=3.7',
}

setup(**setup_kwargs)
