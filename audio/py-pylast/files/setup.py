# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='pylast',
    version='%%PORTVERSION',
    description='A Python interface to Last.fm and Libre.fm',
    long_description='# pyLast\n\n[![PyPI version](https://img.shields.io/pypi/v/pylast.svg)](https://pypi.org/project/pylast/)\n[![Supported Python versions](https://img.shields.io/pypi/pyversions/pylast.svg)](https://pypi.org/project/pylast/)\n[![PyPI downloads](https://img.shields.io/pypi/dm/pylast.svg)](https://pypistats.org/packages/pylast)\n[![Test](https://github.com/pylast/pylast/workflows/Test/badge.svg)](https://github.com/pylast/pylast/actions)\n[![Coverage (Codecov)](https://codecov.io/gh/pylast/pylast/branch/main/graph/badge.svg)](https://codecov.io/gh/pylast/pylast)\n[![Code style: Black](https://img.shields.io/badge/code%20style-Black-000000.svg)](https://github.com/psf/black)\n[![DOI](https://zenodo.org/badge/7803088.svg)](https://zenodo.org/badge/latestdoi/7803088)\n\nA Python interface to [Last.fm](https://www.last.fm/) and other API-compatible websites\nsuch as [Libre.fm](https://libre.fm/).\n\nUse the pydoc utility for help on usage or see [tests/](tests/) for examples.\n\n## Installation\n\nInstall via pip:\n\n```sh\npython3 -m pip install pylast\n```\n\nInstall latest development version:\n\n```sh\npython3 -m pip install -U git+https://github.com/pylast/pylast\n```\n\nOr from requirements.txt:\n\n```txt\n-e https://github.com/pylast/pylast.git#egg=pylast\n```\n\nNote:\n\n* pyLast 5.1+ supports Python 3.7-3.11.\n* pyLast 5.0+ supports Python 3.7-3.10.\n* pyLast 4.3+ supports Python 3.6-3.10.\n* pyLast 4.0 - 4.2 supports Python 3.6-3.9.\n* pyLast 3.2 - 3.3 supports Python 3.5-3.8.\n* pyLast 3.0 - 3.1 supports Python 3.5-3.7.\n* pyLast 2.2 - 2.4 supports Python 2.7.10+, 3.4-3.7.\n* pyLast 2.0 - 2.1 supports Python 2.7.10+, 3.4-3.6.\n* pyLast 1.7 - 1.9 supports Python 2.7, 3.3-3.6.\n* pyLast 1.0 - 1.6 supports Python 2.7, 3.3-3.4.\n* pyLast 0.5 supports Python 2, 3.\n* pyLast < 0.5 supports Python 2.\n\n## Features\n\n * Simple public interface.\n * Access to all the data exposed by the Last.fm web services.\n * Scrobbling support.\n * Full object-oriented design.\n * Proxy support.\n * Internal caching support for some web services calls (disabled by default).\n * Support for other API-compatible networks like Libre.fm.\n\n\n## Getting started\n\nHere\'s some simple code example to get you started. In order to create any object from\npyLast, you need a `Network` object which represents a social music network that is\nLast.fm or any other API-compatible one. You can obtain a pre-configured one for Last.fm\nand use it as follows:\n\n```python\nimport pylast\n\n# You have to have your own unique two values for API_KEY and API_SECRET\n# Obtain yours from https://www.last.fm/api/account/create for Last.fm\nAPI_KEY = "b25b959554ed76058ac220b7b2e0a026"  # this is a sample key\nAPI_SECRET = "425b55975eed76058ac220b7b4e8a054"\n\n# In order to perform a write operation you need to authenticate yourself\nusername = "your_user_name"\npassword_hash = pylast.md5("your_password")\n\nnetwork = pylast.LastFMNetwork(\n    api_key=API_KEY,\n    api_secret=API_SECRET,\n    username=username,\n    password_hash=password_hash,\n)\n\n# Now you can use that object everywhere\ntrack = network.get_track("Iron Maiden", "The Nomad")\ntrack.love()\ntrack.add_tags(("awesome", "favorite"))\n\n# Type help(pylast.LastFMNetwork) or help(pylast) in a Python interpreter\n# to get more help about anything and see examples of how it works\n```\n\nMore examples in\n<a href="https://github.com/hugovk/lastfm-tools">hugovk/lastfm-tools</a> and\n[tests/](https://github.com/pylast/pylast/tree/main/tests).\n\n## Testing\n\nThe [tests/](https://github.com/pylast/pylast/tree/main/tests) directory contains\nintegration and unit tests with Last.fm, and plenty of code examples.\n\nFor integration tests you need a test account at Last.fm that will become cluttered with\ntest data, and an API key and secret. Either copy\n[example_test_pylast.yaml](example_test_pylast.yaml) to test_pylast.yaml and fill out\nthe credentials, or set them as environment variables like:\n\n```sh\nexport PYLAST_USERNAME=TODO_ENTER_YOURS_HERE\nexport PYLAST_PASSWORD_HASH=TODO_ENTER_YOURS_HERE\nexport PYLAST_API_KEY=TODO_ENTER_YOURS_HERE\nexport PYLAST_API_SECRET=TODO_ENTER_YOURS_HERE\n```\n\nTo run all unit and integration tests:\n\n```sh\npython3 -m pip install -e ".[tests]"\npytest\n```\n\nOr run just one test case:\n\n```sh\npytest -k test_scrobble\n```\n\nTo run with coverage:\n\n```sh\npytest -v --cov pylast --cov-report term-missing\ncoverage report # for command-line report\ncoverage html   # for HTML report\nopen htmlcov/index.html\n```\n\n## Logging\n\nTo enable from your own code:\n\n```python\nimport logging\nimport pylast\n\nlogging.basicConfig(level=logging.INFO)\n\n\nnetwork = pylast.LastFMNetwork(...)\n```\n\nTo enable from pytest:\n\n```sh\npytest --log-cli-level info -k test_album_search_images\n```\n\nTo also see data returned from the API, use `level=logging.DEBUG` or\n`--log-cli-level debug` instead.\n',
    author_email='"Amr Hassan <amr.hassan@gmail.com> and Contributors" <amr.hassan@gmail.com>',
    maintainer='Hugo van Kemenade',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
        'Topic :: Internet',
        'Topic :: Multimedia :: Sound/Audio',
        'Topic :: Software Development :: Libraries :: Python Modules',
    ],
    install_requires=[
        'httpx',
        'importlib-metadata; python_version < "3.8"',
    ],
    extras_require={
        'tests': [
            'flaky',
            'pytest',
            'pytest-cov',
            'pytest-random-order',
            'pyyaml',
        ],
    },
    packages=[
        'pylast',
    ],
    package_dir={
        '': 'src',
    },
)
