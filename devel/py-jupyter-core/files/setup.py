# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='jupyter-core',
    version='%%PORTVERSION%%',
    description='Jupyter core package. A base package on which Jupyter projects rely.',
    long_description='There is no reason to install this package on its own.',
    author_email='Jupyter Development Team <jupyter@googlegroups.org>',
    classifiers=[
        'Framework :: Jupyter',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
    ],
    install_requires=[
        'pywin32>=1.0; sys_platform == "win32" and platform_python_implementation != "PyPy"',
        'traitlets',
    ],
    extras_require={
        'test': [
            'ipykernel',
            'pre-commit',
            'pytest',
            'pytest-cov',
            'pytest-timeout',
        ],
    },
    entry_points={
        'console_scripts': [
            'jupyter = jupyter_core.command:main',
            'jupyter-migrate = jupyter_core.migrate:main',
            'jupyter-troubleshoot = jupyter_core.troubleshoot:main',
        ],
    },
    packages=[
        'jupyter_core',
        'jupyter_core.tests',
        'jupyter_core.utils',
    ],
)
