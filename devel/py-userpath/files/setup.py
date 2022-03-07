# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='userpath',
    version='1.8.0',
    description='Cross-platform tool for adding locations to the user PATH',
    long_description="# userpath\n\n| | |\n| --- | --- |\n| CI/CD | [![CI - Test](https://github.com/ofek/userpath/actions/workflows/test.yml/badge.svg)](https://github.com/ofek/userpath/actions/workflows/test.yml) [![CD - Build](https://github.com/ofek/userpath/actions/workflows/build.yml/badge.svg)](https://github.com/ofek/userpath/actions/workflows/build.yml) |\n| Package | [![PyPI - Version](https://img.shields.io/pypi/v/userpath.svg?logo=pypi&label=PyPI&logoColor=gold)](https://pypi.org/project/userpath/) [![PyPI - Python Version](https://img.shields.io/pypi/pyversions/userpath.svg?logo=python&label=Python&logoColor=gold)](https://pypi.org/project/userpath/) |\n| Meta | [![License - MIT](https://img.shields.io/badge/license-MIT-9400d3.svg)](https://spdx.org/licenses/) [![GitHub Sponsors](https://img.shields.io/github/sponsors/ofek?logo=GitHub%20Sponsors&style=social)](https://github.com/sponsors/ofek) |\n\n-----\n\nThis is a tool for modifying a user's `PATH`.\n\n**Table of Contents**\n\n- [Installation](#installation)\n- [CLI](#cli)\n- [API](#api)\n- [License](#license)\n\n## Installation\n\n```console\npip install userpath\n```\n\n## CLI\n\n```console\n$ userpath -h\nUsage: userpath [OPTIONS] COMMAND [ARGS]...\n\nOptions:\n  --version   Show the version and exit.\n  -h, --help  Show this message and exit.\n\nCommands:\n  append   Appends to the user PATH\n  prepend  Prepends to the user PATH\n  verify   Checks if locations are in the user PATH\n```\n\n## API\n\n```pycon\n>>> import userpath\n>>> location = r'C:\\Users\\Ofek\\Desktop\\test'\n>>>\n>>> userpath.in_current_path(location)\nFalse\n>>> userpath.in_new_path(location)\nFalse\n>>> userpath.append(location)\nTrue\n>>> userpath.in_new_path(location)\nTrue\n>>> userpath.need_shell_restart(location)\nTrue\n```\n\n## License\n\n`userpath` is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.\n",
    author_email='Ofek Lev <oss@ofek.dev>',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
    ],
    install_requires=[
        'click',
    ],
    entry_points={
        'console_scripts': [
            'userpath = userpath.cli:userpath',
        ],
    },
    packages=[
        'tests',
        'userpath',
    ],
)
