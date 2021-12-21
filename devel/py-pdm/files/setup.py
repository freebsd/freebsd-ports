# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRE = [
    'appdirs',
    'atoml>=1.0.3',
    'click>=7',
    'importlib-metadata; python_version < "3.8"',
    'installer>=0.3.0,<0.5',
    'packaging',
    'pdm-pep517>=0.9,<0.10',
    'pep517>=0.11.0',
    'pip>=20.1',
    'python-dotenv~=0.15',
    'pythonfinder',
    'resolvelib>=0.8,<0.9',
    'shellingham<2.0.0,>=1.3.2',
    'tomli>=1.1.0,<2.0.0',
    'typing-extensions; python_version < "3.8"',
    'wheel<1.0.0,>=0.36.2',
]
ENTRY_POINTS = {
    'console_scripts': [
        'pdm = pdm.core:main',
    ],
}

setup_kwargs = {
    'name': 'pdm',
    'version': '%%PORTVERSION%%',
    'description': 'Python Development Master',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'frostming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': 'https://pdm.fming.dev',
    'packages': [
        'pdm',
        'pdm._vendor',
        'pdm._vendor.colorama',
        'pdm._vendor.halo',
        'pdm._vendor.log_symbols',
        'pdm._vendor.spinners',
        'pdm.builders',
        'pdm.cli',
        'pdm.cli.commands',
        'pdm.cli.completions',
        'pdm.formats',
        'pdm.installers',
        'pdm.models',
        'pdm.models.in_process',
        'pdm.project',
        'pdm.resolver',
    ],
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'keywords': ['packaging', 'dependency', 'workflow'],
    'classifiers': [
        'Development Status :: 4 - Beta',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Topic :: Software Development :: Build Tools',
    ],
    'install_requires': INSTALL_REQUIRE,
    'python_requires': '>=3.7',
    'entry_points': ENTRY_POINTS,

}


setup(**setup_kwargs)
