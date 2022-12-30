# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='notebook-shim',
    version='%%PORTVERSION%%',
    description='A shim layer for notebook traits and config',
    long_description='# Notebook Shim\n\nThis project provides a way for JupyterLab and other frontends to switch to [Jupyter Server](https://github.com/jupyter/jupyter_server/) for their Python Web application backend.\n\n## Basic Usage\n\nInstall from PyPI:\n\n```\npip install notebook_shim\n```\n\nThis will automatically enable the extension in Jupyter Server.\n\n## Usage\n\nThis project also includes an API for shimming traits that moved from `NotebookApp` in to `ServerApp` in Jupyter Server. This can be used by applications that subclassed `NotebookApp` to leverage the Python server backend of Jupyter Notebooks. Such extensions should *now* switch to `ExtensionApp` API in Jupyter Server and add `NotebookConfigShimMixin` in their inheritance list to properly handle moved traits.\n\nFor example, an application class that previously looked like:\n\n```python\nfrom notebook.notebookapp import NotebookApp\n\nclass MyApplication(NotebookApp):\n```\n\nshould switch to look something like:\n\n```python\nfrom jupyter_server.extension.application import ExtensionApp\nfrom notebook_shim.shim import NotebookConfigShimMixin\n\nclass MyApplication(NotebookConfigShimMixin, ExtensionApp):\n```',
    author_email='Jupyter Development Team <jupyter@googlegroups.com>',
    classifiers=[
        'Framework :: Jupyter',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    install_requires=[
        'jupyter-server<3,>=1.8',
    ],
    extras_require={
        'test': [
            'pytest',
            'pytest-console-scripts',
            'pytest-tornasync',
        ],
    },
    packages=[
        'notebook_shim',
        'notebook_shim.tests',
    ],
)
