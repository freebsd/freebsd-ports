# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRES = [
    'blinker',
    'cachecontrol>=0.12.11',
    'certifi>=2022.6.15',
    'findpython>=0.2.0',
    'importlib-metadata>=3.6; python_version < "3.10"',
    'installer<0.7,>=0.6',
    'packaging>=20.9',
    'pdm-pep517<2.0.0,>=1.0.0',
    'pep517>=0.11.0',
    'platformdirs',
    'python-dotenv>=0.15',
    'requests-toolbelt',
    'resolvelib<0.9,>=0.8',
    'rich>=12.3.0',
    'shellingham>=1.3.2',
    'tomli>=1.1.0; python_version < "3.11"',
    'tomlkit<1,>=0.8.0',
    'typing-extensions; python_version < "3.8"',
    'unearth>=0.6.0',
    'virtualenv>=20',
]
ENTRY_POINTS = {
    'console_scripts': [
        'pdm = pdm.core:main',
    ],
}

setup_kwargs = {
    'name': 'pdm',
    'version': '%%PORTVERSION%%',
    'description': 'A modern Python package and dependency manager supporting the latest PEP standards',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'frostming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': '',
    'packages': [
        'pdm.builders',
        'pdm.cli',
        'pdm.cli.commands',
        'pdm.cli.commands.publish',
        'pdm.cli.commands.venv',
        'pdm.cli.completions',
        'pdm.formats',
        'pdm.installers',
        'pdm.models',
        'pdm.models.in_process',
        'pdm.pep582',
        'pdm.project',
        'pdm.resolver',
    ],
    'package_dir': {'': 'src'},
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'keywords': ['packaging', 'dependency', 'workflow'],
    'classifiers': [
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Topic :: Software Development :: Build Tools',
    ],
    'install_requires': INSTALL_REQUIRES,
    'python_requires': '>=3.7',
    'entry_points': ENTRY_POINTS,
}

setup(**setup_kwargs)
