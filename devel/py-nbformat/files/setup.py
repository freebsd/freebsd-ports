# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='nbformat',
    version='%%PORTVERSION%%',
    description='The Jupyter Notebook format',
    long_description='This package contains the base implementation of the Jupyter Notebook format,\nand Python APIs for working with notebooks.',
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
    ],
    install_requires=[
        'fastjsonschema',
        'importlib-metadata>=3.6; python_version < "3.8"',
        'jsonschema>=2.6',
        'jupyter-core',
        'traitlets>=5.1',
    ],
    extras_require={
        'test': [
            'check-manifest',
            'pep440',
            'pre-commit',
            'pytest',
            'testpath',
        ],
    },
    entry_points={
        'console_scripts': [
            'jupyter-trust = nbformat.sign:TrustNotebookApp.launch_instance',
        ],
    },
    packages=[
        'nbformat',
        'nbformat.corpus',
        'nbformat.corpus.tests',
        'nbformat.v1',
        'nbformat.v2',
        'nbformat.v3',
        'nbformat.v4',
    ],
    package_data = {
        'nbformat' : [
            '**/nbformat.**.schema.json',
        ]
    },
)
