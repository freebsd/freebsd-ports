# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='ipykernel',
    version='%%PORTVERSION%%',
    description='IPython Kernel for Jupyter',
    long_description='# IPython Kernel for Jupyter\n\nThis package provides the IPython kernel for Jupyter.\n\n## Installation from source\n\n1. `git clone`\n2. `cd ipykernel`\n3. `pip install -e ".[test]"`\n\nAfter that, all normal `ipython` commands will use this newly-installed version of the kernel.\n\n## Running tests\n\nFollow the instructions from `Installation from source`.\n\nand then from the root directory\n\n```bash\npytest ipykernel\n```\n\n## Running tests with coverage\n\nFollow the instructions from `Installation from source`.\n\nand then from the root directory\n\n```bash\npytest ipykernel -vv -s --cov ipykernel --cov-branch --cov-report term-missing:skip-covered --durations 10\n```\n',
    author_email='IPython Development Team <ipython-dev@scipy.org>',
    classifiers=[
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
    ],
    install_requires=[
        'appnope; platform_system == "Darwin"',
        'debugpy>=1.0',
        'ipython>=7.23.1',
        'jupyter-client>=6.1.12',
        'matplotlib-inline>=0.1',
        'nest-asyncio',
        'packaging',
        'pyzmq>=17',
        'psutil',
        'tornado>=6.1',
        'traitlets>=5.1.0',
    ],
    extras_require={
        'test': [
            'flaky',
            'ipyparallel',
            'pre-commit',
            'pytest-cov',
            'pytest-timeout',
            'pytest>=6.0',
        ],
    },
    packages=[
        'ipykernel',
        'ipykernel.comm',
        'ipykernel.gui',
        'ipykernel.inprocess',
        'ipykernel.inprocess.tests',
        'ipykernel.pylab',
        'ipykernel.tests',
    ],
)
