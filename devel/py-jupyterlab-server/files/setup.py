# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='jupyterlab-server',
    version='%%PORTVERSION%%',
    description='A set of server components for JupyterLab and JupyterLab like applications.',
    long_description='# jupyterlab server\n\n[![Coverage](https://codecov.io/gh/jupyterlab/jupyterlab_server/branch/master/graph/badge.svg)](https://codecov.io/gh/jupyterlab/jupyterlab_server)\n[![Build Status](https://github.com/jupyterlab/jupyterlab_server/workflows/Tests/badge.svg?branch=master)](https://github.com/jupyterlab/jupyterlab_server/actions?query=branch%3Amaster+workflow%3A%22Tests%22)\n[![Documentation Status](https://readthedocs.org/projects/jupyterlab_server/badge/?version=stable)](http://jupyterlab_server.readthedocs.io/en/stable/)\n\n## Motivation\n\nJupyterLab Server sits between JupyterLab and Jupyter Server, and provides a\nset of REST API handlers and utilities that are used by JupyterLab. It is a separate project in order to\naccommodate creating JupyterLab-like applications from a more limited scope.\n\n## Install\n\n`pip install jupyterlab_server`\n\nTo include optional `openapi` dependencies, use:\n\n`pip install jupyterlab_server[openapi]`\n\nTo include optional `pytest_plugin` dependencies, use:\n\n`pip install jupyterlab_server[test]`\n\n## Usage\n\nSee the full documentation for [API docs](https://jupyterlab-server.readthedocs.io/en/stable/api/index.html) and [REST endpoint descriptions](https://jupyterlab-server.readthedocs.io/en/stable/api/rest.html).\n\n## Extending the Application\n\nSubclass the `LabServerApp` and provide additional traits and handlers as appropriate for your application.\n\n## Contribution\n\nPlease see `CONTRIBUTING.md` for details.\n',
    author_email='Jupyter Development Team <jupyter@googlegroups.com>',
    classifiers=[
        'Framework :: Jupyter',
        'Framework :: Jupyter :: JupyterLab',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    install_requires=[
        'babel',
        'importlib-metadata>=4.8.1; python_version < "3.10"',
        'jinja2>=3.0.3',
        'json5',
        'jsonschema>=3.0.1',
        'jupyter-server<3,>=1.8',
        'packaging',
        'requests',
    ],
    extras_require={
        'docs': [
             'autodoc-traits',
             'docutils<0.19',
             'pydata_sphinx_theme',
             'sphinx',
             'sphinx-copybutton',
             'sphinxcontrib-openapi',
             'myst-parser',
             'mistune<1',
             'jinja2<3.1.0'
        ],
        'openapi': [
            'openapi-core>=0.14.2',
            'ruamel-yaml',
        ],
        'test': [
            'codecov',
            'ipykernel',
            'jupyter-server[test]',
            'openapi_core~=0.14.2',
            'openapi-spec-validator<0.5',
            'pytest>=7.0',
            'pytest-console-scripts',
            'pytest-cov',
            'requests_mock',
            'ruamel-yaml',
            'strict-rfc3339',
        ],
    },
    packages=[
        'jupyterlab_server',
    ],
)
