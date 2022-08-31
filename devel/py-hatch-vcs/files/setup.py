# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='hatch-vcs',
    version='%%PORTVERSION%%',
    description='Hatch plugin for versioning with your preferred VCS',
    long_description='# hatch-vcs\n\n| | |\n| --- | --- |\n| CI/CD | [![CI - Test](https://github.com/ofek/hatch-vcs/actions/workflows/test.yml/badge.svg)](https://github.com/ofek/hatch-vcs/actions/workflows/test.yml) [![CD - Build](https://github.com/ofek/hatch-vcs/actions/workflows/build.yml/badge.svg)](https://github.com/ofek/hatch-vcs/actions/workflows/build.yml) |\n| Package | [![PyPI - Version](https://img.shields.io/pypi/v/hatch-vcs.svg?logo=pypi&label=PyPI&logoColor=gold)](https://pypi.org/project/hatch-vcs/) [![PyPI - Python Version](https://img.shields.io/pypi/pyversions/hatch-vcs.svg?logo=python&label=Python&logoColor=gold)](https://pypi.org/project/hatch-vcs/) |\n| Meta | [![code style - black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black) [![types - Mypy](https://img.shields.io/badge/types-Mypy-blue.svg)](https://github.com/ambv/black) [![imports - isort](https://img.shields.io/badge/imports-isort-ef8336.svg)](https://github.com/pycqa/isort) [![License - MIT](https://img.shields.io/badge/license-MIT-9400d3.svg)](https://spdx.org/licenses/) [![GitHub Sponsors](https://img.shields.io/github/sponsors/ofek?logo=GitHub%20Sponsors&style=social)](https://github.com/sponsors/ofek) |\n\n-----\n\nThis provides a plugin for [Hatch](https://github.com/ofek/hatch) that uses your preferred version control system (like Git) to determine project versions.\n\n**Table of Contents**\n\n- [Global dependency](#global-dependency)\n- [Version source](#version-source)\n  - [Version source options](#version-source-options)\n- [Build hook](#build-hook)\n  - [Build hook options](#build-hook-options)\n- [License](#license)\n\n## Global dependency\n\nEnsure `hatch-vcs` is defined within the `build-system.requires` field in your `pyproject.toml` file.\n\n```toml\n[build-system]\nrequires = ["hatchling", "hatch-vcs"]\nbuild-backend = "hatchling.build"\n```\n\n## Version source\n\nThe [version source plugin](https://ofek.dev/hatch/latest/plugins/version-source/) name is `vcs`.\n\n- ***pyproject.toml***\n\n    ```toml\n    [tool.hatch.version]\n    source = "vcs"\n    ```\n\n- ***hatch.toml***\n\n    ```toml\n    [version]\n    source = "vcs"\n    ```\n\n### Version source options\n\n| Option | Type | Default | Description |\n| --- | --- | --- | --- |\n| `tag-pattern` | `str` | see [code](https://github.com/pypa/setuptools_scm/blob/v6.4.0/src/setuptools_scm/config.py#L13) | A regular expression used to extract the version part from VCS tags. The pattern needs to contain either a single match group, or a group named `version`, that captures the actual version information. |\n| `fallback-version` | `str` | | The version that will be used if no other method for detecting the version is successful. If not specified, unsuccessful version detection will raise an error. |\n| `raw-options` | `dict` | | A table of [`setuptools-scm` parameters](https://github.com/pypa/setuptools_scm#configuration-parameters) that will override any of the options listed above. The `write_to` and `write_to_template` parameters are ignored. |\n\n## Build hook\n\nThe [build hook plugin](https://ofek.dev/hatch/latest/plugins/build-hook/) name is `vcs`.\n\n- ***pyproject.toml***\n\n    ```toml\n    [tool.hatch.build.hooks.vcs]\n    ```\n\n- ***hatch.toml***\n\n    ```toml\n    [build.hooks.vcs]\n    ```\n\n### Build hook options\n\n| Option | Type | Default | Description |\n| --- | --- | --- | --- |\n| `version-file` | `str` | ***REQUIRED*** | The relative path to the file that gets updated with the current version. |\n| `template` | `str` | | The template used to overwrite the `version-file`. See the [code](https://github.com/pypa/setuptools_scm/blob/v6.4.0/src/setuptools_scm/__init__.py#L30-L39) for the default template for each file extension. |\n\n## License\n\n`hatch-vcs` is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.\n',
    author_email='Ofek Lev <oss@ofek.dev>',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
    ],
    install_requires=[
        'hatchling>=0.21.0',
        'setuptools-scm<6; python_version < "3"',
        'setuptools-scm>=6.4.0; python_version > "3"',
    ],
    entry_points={
        'hatch': [
            'vcs = hatch_vcs.hooks',
        ],
    },
    packages=[
        'hatch_vcs',
    ],
)
