
# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
EXTRAS_REQUIRE = {
    'setuptools': [
        'setuptools>=42',
        'wheel',
        'editables==0.2',
    ],
}
ENTRY_POINTS = {
    'distutils.commands': [
        'editable_wheel = pdm.pep517.setuptools.editable:editable_wheel',
    ],
}

setup_kwargs = {
    'name': 'pdm-pep517',
    'version': '0.8.4',
    'description': 'A PEP 517 backend for PDM that supports PEP 621 metadata',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'Frost Ming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': 'https://pdm.fming.dev',
    'packages': [
        'pdm.pep517',
        'pdm.pep517._vendor',
        'pdm.pep517._vendor.cerberus',
        'pdm.pep517._vendor.packaging',
        'pdm.pep517._vendor.toml',
    ],
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'keywords': ['packaging', 'PEP 517', 'build'],
    'classifiers': [
        'Development Status :: 3 - Alpha',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Topic :: Software Development :: Build Tools',
    ],
    'extras_require': EXTRAS_REQUIRE,
    'python_requires': '>=3.6',
    'entry_points': ENTRY_POINTS,

}


setup(**setup_kwargs)
