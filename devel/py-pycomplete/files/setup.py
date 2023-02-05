# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRES = [
]
EXTRAS_REQUIRE = {
    'dev': [
        'pytest<7.0.0,>=6.1.1',
        'click<8.0.0,>=7.1.2',
    ],
}
ENTRY_POINTS = {
    'console_scripts': [
        'pycomplete = pycomplete.__main__:main',
    ],
}

setup_kwargs = {
    'name': 'pycomplete',
    'version': '%%PORTVERSION%%',
    'description': 'A Python library to generate static completion scripts for your CLI app',
    'long_description': long_description,
    'license': 'BSD-3-Clause',
    'author': '',
    'author_email': 'Frost Ming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': '',
    'packages': [
        'pycomplete',
        'pycomplete.templates',
    ],
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'keywords': ['cli', 'shell'],
    'classifiers': [
        'Development Status :: 3 - Alpha',
    ],
    'install_requires': INSTALL_REQUIRES,
    'extras_require': EXTRAS_REQUIRE,
    'python_requires': '>=3.6',
    'entry_points': ENTRY_POINTS,
}

setup(**setup_kwargs)
