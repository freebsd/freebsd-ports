# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='hatch-fancy-pypi-readme',
    version='%%PORTVERSION%%',
    description='Fancy PyPI READMEs with Hatch',
    long_description='# Your ✨Fancy✨ Project Deserves a ✨Fancy✨ PyPI Readme! 🧐\n\n[![PyPI - Version](https://img.shields.io/pypi/v/hatch-fancy-pypi-readme.svg)](https://pypi.org/project/hatch-fancy-pypi-readme)\n[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/hatch-fancy-pypi-readme.svg)](https://pypi.org/project/hatch-fancy-pypi-readme)\n[![Hatch project](https://img.shields.io/badge/%F0%9F%A5%9A-Hatch-4051b5.svg)](https://github.com/pypa/hatch)\n[![License: MIT](https://img.shields.io/badge/license-MIT-C06524)](https://github.com/hynek/hatch-fancy-pypi-readme/blob/main/LICENSE.txt)\n\n\n*hatch-fancy-pypi-readme* is an MIT-licensed metadata plugin for [*Hatch*](https://hatch.pypa.io/).\n\nIts purpose is to help you to have fancy PyPI readmes – unlike *this* one you’re looking at right now.\n\nPlease check out the [documentation](https://github.com/hynek/hatch-fancy-pypi-readme#readme) to see what *hatch-fancy-pypi-readme* can do for you and your projects!\n',
    author_email='Hynek Schlawack <hs@ox.cx>',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Framework :: Hatch',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
        'Topic :: Software Development :: Build Tools',
    ],
    install_requires=[
        'hatchling',
        'tomli; python_version < "3.11"',
        'typing-extensions; python_version < "3.8"',
    ],
    extras_require={
        'dev': [
            'hatch-fancy-pypi-readme[tests]',
            'mypy',
        ],
        'tests': [
            'build',
            'pytest',
            'wheel',
        ],
    },
    entry_points={
        'console_scripts': [
            'hatch-fancy-pypi-readme = hatch_fancy_pypi_readme.__main__:main',
        ],
        'hatch': [
            'fancy-pypi-readme = hatch_fancy_pypi_readme.hooks',
        ],
    },
    packages=[
        'hatch_fancy_pypi_readme',
    ],
    package_dir={
        '': 'src',
    },
)
