# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRES = [
    'packaging>=20',
]
ENTRY_POINTS = {
    'console_scripts': [
        'findpython = findpython.__main__:main',
    ],
}

setup_kwargs = {
    'name': 'findpython',
    'version': '%%PORTVERSION%%',
    'description': 'A utility to find python versions on your system',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'Frost Ming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': '',
    'packages': [
        'findpython',
        'findpython._vendor',
        'findpython._vendor.pep514tools',
        'findpython.providers',
    ],
    'package_dir': {'': 'src'},
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'classifiers': [
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    'install_requires': INSTALL_REQUIRES,
    'python_requires': '>=3.7',
    'entry_points': ENTRY_POINTS,
}

setup(**setup_kwargs)
