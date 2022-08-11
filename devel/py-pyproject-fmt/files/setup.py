# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='pyproject-fmt',
    version='%%PORTVERSION%%',
    description='Format your pyproject.toml file',
    long_description='# pyproject-fmt\n\n[![PyPI](https://img.shields.io/pypi/v/pyproject-fmt?style=flat-square)](https://pypi.org/project/pyproject-fmt)\n[![PyPI - Implementation](https://img.shields.io/pypi/implementation/pyproject-fmt?style=flat-square)](https://pypi.org/project/pyproject-fmt)\n[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/pyproject-fmt?style=flat-square)](https://pypi.org/project/pyproject-fmt)\n[![PyPI - Downloads](https://img.shields.io/pypi/dm/pyproject-fmt?style=flat-square)](https://pypistats.org/packages/pyproject-fmt)\n[![PyPI - License](https://img.shields.io/pypi/l/pyproject-fmt?style=flat-square)](https://opensource.org/licenses/MIT)\n[![check](https://github.com/tox-dev/pyproject-fmt/actions/workflows/check.yml/badge.svg)](https://github.com/tox-dev/pyproject-fmt/actions/workflows/check.yml)\n\nApply a consistent format to `pyproject.toml` files.\n[Read the full documentation here](https://pyproject-fmt.readthedocs.io/en/latest/).\n',
    author_email='Bernat Gabor <gaborjbernat@gmail.com>',
    classifiers=[
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
    ],
    install_requires=[
        'packaging>=21.3',
        'tomlkit>=0.10',
        'typing-extensions>=3.10; python_version < "3.8"',
    ],
    extras_require={
        'docs': [
            'furo>=2022.1.2b11',
            'sphinx-argparse-cli>=1.8',
            'sphinx-autodoc-typehints>=1.17',
            'sphinx-copybutton>=0.5',
            'sphinx>=4.4',
        ],
        'test': [
            'covdefaults>=2',
            'pytest-cov>=3',
            'pytest-mock>=3.7',
            'pytest>=7',
        ],
    },
    entry_points={
        'console_scripts': [
            'pyproject-fmt = pyproject_fmt.__main__:run',
        ],
    },
    packages=[
        'pyproject_fmt',
        'pyproject_fmt.formatter',
    ],
    package_dir={
        '': 'src'
    },
)
