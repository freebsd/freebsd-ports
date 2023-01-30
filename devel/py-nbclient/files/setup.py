# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='nbclient',
    version='%%PORTVERSION%%',
    description="A client library for executing notebooks. Formerly nbconvert's ExecutePreprocessor.",
    long_description="[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/jupyter/nbclient/main?filepath=binder%2Frun_nbclient.ipynb)\n[![Build Status](https://github.com/jupyter/nbclient/workflows/CI/badge.svg)](https://github.com/jupyter/nbclient/actions)\n[![Documentation Status](https://readthedocs.org/projects/nbclient/badge/?version=latest)](https://nbclient.readthedocs.io/en/latest/?badge=latest)\n[![image](https://codecov.io/github/jupyter/nbclient/coverage.svg?branch=main)](https://codecov.io/github/jupyter/nbclient?branch=main)\n[![Python 3.7](https://img.shields.io/badge/python-3.7-blue.svg)](https://www.python.org/downloads/release/python-370/)\n[![Python 3.8](https://img.shields.io/badge/python-3.8-blue.svg)](https://www.python.org/downloads/release/python-380/)\n[![Python 3.9](https://img.shields.io/badge/python-3.9-blue.svg)](https://www.python.org/downloads/release/python-390/)\n[![Python 3.10](https://img.shields.io/badge/python-3.10-blue.svg)](https://www.python.org/downloads/release/python-3100/)\n[![Python 3.11](https://img.shields.io/badge/python-3.11-blue.svg)](https://www.python.org/downloads/release/python-3110/)\n[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/ambv/black)\n\n# nbclient\n\n**NBClient** lets you **execute** notebooks.\n\nA client library for programmatic notebook execution, **NBClient** is a tool for running Jupyter Notebooks in\ndifferent execution contexts, including the command line.\n\n## Interactive Demo\n\nTo demo **NBClient** interactively, click this Binder badge to start the demo:\n\n[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/jupyter/nbclient/main?filepath=binder%2Frun_nbclient.ipynb)\n\n## Installation\n\nIn a terminal, run:\n\n```\npython3 -m pip install nbclient\n```\n\n## Documentation\n\nSee [ReadTheDocs](https://nbclient.readthedocs.io/en/latest/) for more in-depth details about the project and the\n[API Reference](https://nbclient.readthedocs.io/en/latest/reference/index.html).\n\n## Python Version Support\n\nThis library currently supports Python 3.6+ versions. As minor Python\nversions are officially sunset by the Python org, nbclient will similarly\ndrop support in the future.\n\n## Origins\n\nThis library used to be part of the [nbconvert](https://nbconvert.readthedocs.io/en/latest/) project. NBClient extracted nbconvert's `ExecutePreprocessor`into its own library for easier updating and importing by downstream libraries and applications.\n\n## Relationship to JupyterClient\n\nNBClient and JupyterClient are distinct projects.\n\n`jupyter_client` is a client library for the jupyter protocol. Specifically, `jupyter_client` provides the Python API\nfor starting, managing and communicating with Jupyter kernels.\n\nWhile, nbclient allows notebooks to be run in different execution contexts.\n",
    author_email='Jupyter Development Team <jupyter@googlegroups.com>',
    classifiers=[
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
    ],
    install_requires=[
        'jupyter-client>=6.1.12',
        'jupyter-core!=5.0.*,>=4.12',
        'nbformat>=5.1',
        'traitlets>=5.3',
    ],
    extras_require={
        'dev': [
            'pre-commit',
        ],
        'docs': [
            'autodoc-traits',
            'mock',
            'moto',
            'myst-parser',
            'nbclient[test]',
            'sphinx-book-theme',
            'sphinx>=1.7',
        ],
        'test': [
            'ipykernel',
            'ipython',
            'ipywidgets',
            'nbconvert>=7.0.0',
            'pytest-asyncio',
            'pytest-cov>=4.0',
            'pytest>=7.0',
            'testpath',
            'xmltodict',
        ],
    },
    entry_points={
        'console_scripts': [
            'jupyter-execute = nbclient.cli:main',
        ],
    },
    packages=[
        'nbclient',
        'nbclient.tests',
    ],
)
