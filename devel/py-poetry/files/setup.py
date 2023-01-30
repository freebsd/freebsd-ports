# -*- coding: utf-8 -*-
from setuptools import setup

package_dir = \
{'': 'src'}

packages = \
['poetry',
 'poetry.config',
 'poetry.console',
 'poetry.console.commands',
 'poetry.console.commands.cache',
 'poetry.console.commands.debug',
 'poetry.console.commands.env',
 'poetry.console.commands.self',
 'poetry.console.commands.self.show',
 'poetry.console.commands.source',
 'poetry.console.events',
 'poetry.console.io',
 'poetry.console.io.inputs',
 'poetry.console.logging',
 'poetry.console.logging.formatters',
 'poetry.inspection',
 'poetry.installation',
 'poetry.installation.operations',
 'poetry.json',
 'poetry.layouts',
 'poetry.masonry',
 'poetry.masonry.builders',
 'poetry.mixology',
 'poetry.mixology.solutions',
 'poetry.mixology.solutions.providers',
 'poetry.mixology.solutions.solutions',
 'poetry.packages',
 'poetry.plugins',
 'poetry.publishing',
 'poetry.puzzle',
 'poetry.repositories',
 'poetry.repositories.link_sources',
 'poetry.utils',
 'poetry.vcs',
 'poetry.vcs.git',
 'poetry.version']

package_data = \
{'': ['*'], 'poetry': ['_vendor/*'], 'poetry.json': ['schemas/*']}

install_requires = \
['cachecontrol[filecache]>=0.12.9,<0.13.0',
 'cleo>=2.0.0,<3.0.0',
 'crashtest>=0.4.1,<0.5.0',
 'dulwich>=0.20.46,<0.21.0',
 'filelock>=3.8.0,<4.0.0',
 'html5lib>=1.0,<2.0',
 'jsonschema>=4.10.0,<5.0.0',
 'keyring>=23.9.0,<24.0.0',
 'lockfile>=0.12.2,<0.13.0',
 'packaging>=20.4',
 'pexpect>=4.7.0,<5.0.0',
 'pkginfo>=1.5,<2.0',
 'platformdirs>=2.5.2,<3.0.0',
 'poetry-core==1.4.0',
 'poetry-plugin-export>=1.2.0,<2.0.0',
 'requests-toolbelt>=0.9.1,<0.11.0',
 'requests>=2.18,<3.0',
 'shellingham>=1.5,<2.0',
 'tomlkit>=0.11.1,<1.0.0,!=0.11.2,!=0.11.3',
 'trove-classifiers>=2022.5.19',
 'urllib3>=1.26.0,<2.0.0']

extras_require = \
{':python_version < "3.10"': ['importlib-metadata>=4.4,<5.0'],
 ':python_version < "3.11"': ['tomli>=2.0.1,<3.0.0'],
 ':python_version < "3.8"': ['backports.cached-property>=1.0.2,<2.0.0'],
 ':sys_platform != "win32" or python_version != "3.9"': ['virtualenv>=20.4.3,<21.0.0,!=20.4.5,!=20.4.6'],
 ':sys_platform == "win32" and python_version == "3.9"': ['virtualenv>=20.4.3,<21.0.0,!=20.4.5,!=20.4.6,<20.16.6']}

entry_points = \
{'console_scripts': ['poetry = poetry.console.application:main']}

setup_kwargs = {
    'name': 'poetry',
    'version': '%%PORTVERSION%%',
    'description': 'Python dependency management and packaging made easy.',
    'long_description': '# Poetry: Python packaging and dependency management made easy\n\n[![Stable Version](https://img.shields.io/pypi/v/poetry?label=stable)][PyPI Releases]\n[![Pre-release Version](https://img.shields.io/github/v/release/python-poetry/poetry?label=pre-release&include_prereleases&sort=semver)][PyPI Releases]\n[![Python Versions](https://img.shields.io/pypi/pyversions/poetry)][PyPI]\n[![Download Stats](https://img.shields.io/pypi/dm/poetry)](https://pypistats.org/packages/poetry)\n[![Discord](https://img.shields.io/discord/487711540787675139?logo=discord)][Discord]\n\nPoetry helps you declare, manage and install dependencies of Python projects,\nensuring you have the right stack everywhere.\n\n![Poetry Install](https://raw.githubusercontent.com/python-poetry/poetry/master/assets/install.gif)\n\nPoetry replaces `setup.py`, `requirements.txt`, `setup.cfg`, `MANIFEST.in` and `Pipfile` with a simple `pyproject.toml`\nbased project format.\n\n```toml\n[tool.poetry]\nname = "my-package"\nversion = "0.1.0"\ndescription = "The description of the package"\n\nlicense = "MIT"\n\nauthors = [\n    "Sébastien Eustace <sebastien@eustace.io>"\n]\n\nrepository = "https://github.com/python-poetry/poetry"\nhomepage = "https://python-poetry.org"\n\n# README file(s) are used as the package description\nreadme = ["README.md", "LICENSE"]\n\n# Keywords (translated to tags on the package index)\nkeywords = ["packaging", "poetry"]\n\n[tool.poetry.dependencies]\n# Compatible Python versions\npython = ">=3.8"\n# Standard dependency with semver constraints\naiohttp = "^3.8.1"\n# Dependency with extras\nrequests = { version = "^2.28", extras = ["security"] }\n# Version-specific dependencies with prereleases allowed\ntomli = { version = "^2.0.1", python = "<3.11", allow-prereleases = true }\n# Git dependencies\ncleo = { git = "https://github.com/python-poetry/cleo.git", branch = "master" }\n# Optional dependencies (installed by extras)\npendulum = { version = "^2.1.2", optional = true }\n\n# Dependency groups are supported for organizing your dependencies\n[tool.poetry.group.dev.dependencies]\npytest = "^7.1.2"\npytest-cov = "^3.0"\n\n# ...and can be installed only when explicitly requested\n[tool.poetry.group.docs]\noptional = true\n[tool.poetry.group.docs.dependencies]\nSphinx = "^5.1.1"\n\n# Python-style entrypoints and scripts are easily expressed\n[tool.poetry.scripts]\nmy-script = "my_package:main"\n```\n\n## Installation\n\nPoetry supports multiple installation methods, including a simple script found at [install.python-poetry.org]. For full\ninstallation instructions, including advanced usage of the script, alternate install methods, and CI best practices, see\nthe full [installation documentation].\n\n## Documentation\n\n[Documentation] for the current version of Poetry (as well as the development branch and recently out of support\nversions) is available from the [official website].\n\n## Contribute\n\nPoetry is a large, complex project always in need of contributors. For those new to the project, a list of\n[suggested issues] to work on in Poetry and poetry-core is available. The full [contributing documentation] also\nprovides helpful guidance.\n\n## Resources\n\n* [Releases][PyPI Releases]\n* [Official Website]\n* [Documentation]\n* [Issue Tracker]\n* [Discord]\n\n  [PyPI]: https://pypi.org/project/poetry/\n  [PyPI Releases]: https://pypi.org/project/poetry/#history\n  [Official Website]: https://python-poetry.org\n  [Documentation]: https://python-poetry.org/docs/\n  [Issue Tracker]: https://github.com/python-poetry/poetry/issues\n  [Suggested Issues]: https://github.com/python-poetry/poetry/contribute\n  [Contributing Documentation]: https://python-poetry.org/docs/contributing\n  [Discord]: https://discord.com/invite/awxPgve\n  [install.python-poetry.org]: https://install.python-poetry.org\n  [Installation Documentation]: https://python-poetry.org/docs/#installation\n\n## Related Projects\n\n* [poetry-core](https://github.com/python-poetry/poetry-core): PEP 517 build-system for Poetry projects, and\ndependency-free core functionality of the Poetry frontend\n* [poetry-plugin-export](https://github.com/python-poetry/poetry-plugin-export): Export Poetry projects/lock files to\nforeign formats like requirements.txt\n* [poetry-plugin-bundle](https://github.com/python-poetry/poetry-plugin-bundle): Install Poetry projects/lock files to\nexternal formats like virtual environments\n* [install.python-poetry.org](https://github.com/python-poetry/install.python-poetry.org): The official Poetry\ninstallation script\n* [website](https://github.com/python-poetry/website): The official Poetry website and blog\n',
    'author': 'Sébastien Eustace',
    'author_email': 'sebastien@eustace.io',
    'maintainer': 'Arun Babu Neelicattu',
    'maintainer_email': 'arun.neelicattu@gmail.com',
    'url': 'https://python-poetry.org/',
    'package_dir': package_dir,
    'packages': packages,
    'package_data': package_data,
    'install_requires': install_requires,
    'extras_require': extras_require,
    'entry_points': entry_points,
    'python_requires': '>=3.7,<4.0',
}

setup(**setup_kwargs)
