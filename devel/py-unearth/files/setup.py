# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
INSTALL_REQUIRE = [
    'packaging>=20',
    'requests>=2.25',
    'cached-property>=1.5.2; python_version < "3.8"',
]
EXTRAS_REQUIRE = {
    'keyring': [
        'keyring',
    ],
}
ENTRY_POINTS = {
    'console_scripts': [
        'unearth = unearth.__main__:cli',
    ],
}

setup_kwargs = {
    'name': 'unearth',
    'version': '%%PORTVERSION%%',
    'description': 'A utility to fetch and download python packages',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'Frost Ming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': '',
    'packages': [
        'unearth',
        'unearth.vcs',
    ],
    'package_dir': {'': 'src'},
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'classifiers': [
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    'install_requires': INSTALL_REQUIRE,
    'extras_require': EXTRAS_REQUIRE,
    'python_requires': '>=3.7',
    'entry_points': ENTRY_POINTS,
}

setup(**setup_kwargs)
