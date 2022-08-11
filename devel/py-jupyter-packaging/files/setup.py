# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='jupyter-packaging',
    version='%%PORTVERSION%%',
    description='Jupyter Packaging Utilities.',
    long_description='# Jupyter Packaging\n\nTools to help build and install Jupyter Python packages that require a pre-build step that may include JavaScript build steps.\n\n## Install\n\n`pip install jupyter-packaging`\n\n## Usage\n\nThere are three ways to use `jupyter-packaging` in another package.\nIn general, you should not depend on `jupyter_packaging` as a runtime dependency, only as a build dependency.\n\n### As a Build Requirement\n\nUse a `pyproject.toml` file as outlined in [pep-518](https://www.python.org/dev/peps/pep-0518/).\nAn example:\n\n```toml\n[build-system]\nrequires = ["jupyter_packaging>=0.10,<2"]\nbuild-backend = "setuptools.build_meta"\n```\n\nBelow is an example `setup.py` using the above config.\nIt assumes the rest of your metadata is in [`setup.cfg`](https://setuptools.readthedocs.io/en/latest/userguide/declarative_config.html).\nWe wrap the import in a try/catch to allow the file to be run without `jupyter_packaging`\nso that `python setup.py` can be run directly when not building.\n\n```py\nfrom setuptools import setup\n\ntry:\n    from jupyter_packaging import wrap_installers, npm_builder\n    builder = npm_builder()\n    cmdclass = wrap_installers(pre_develop=builder, pre_dist=builder)\nexcept ImportError:\n    cmdclass = {}\n\nsetup(cmdclass=cmdclass))\n```\n\n### As a Build Backend\n\nUse the `jupyter_packaging` build backend.\nThe pre-build command is specified as metadata in `pyproject.toml`:\n\n```toml\n[build-system]\nrequires = ["jupyter_packaging>=0.10,<2"]\nbuild-backend = "jupyter_packaging.build_api"\n\n[tool.jupyter-packaging.builder]\nfactory = "jupyter_packaging.npm_builder"\n\n[tool.jupyter-packaging.build-args]\nbuild_cmd = "build:src"\n```\n\nThe corresponding `setup.py` would be greatly simplified:\n\n```py\nfrom setuptools import setup\nsetup()\n```\n\nThe `tool.jupyter-packaging.builder` section expects a `func` value that points to an importable\nmodule and a function with dot separators.  If not given, no pre-build function will run.\n\nThe optional `tool.jupyter-packaging.build-args` sections accepts a dict of keyword arguments to\ngive to the pre-build command.\n\nThe build backend does not handle the `develop` command (`pip install -e .`).\nIf desired, you can wrap just that command:\n\n```py\nimport setuptools\n\ntry:\n    from jupyter_packaging import wrap_installers, npm_builder\n    builder = npm_builder(build_cmd="build:dev")\n    cmdclass = wrap_installers(pre_develop=builder)\nexcept ImportError:\n    cmdclass = {}\n\nsetup(cmdclass=cmdclass))\n```\n\nThe optional `tool.jupyter-packaging.options` section accepts the following options:\n\n- `skip-if-exists`: A list of local files whose presence causes the prebuild to skip\n- `ensured-targets`: A list of local file paths that should exist when the dist commands are run\n\n### As a Vendored File\n\nVendor `setupbase.py` locally alongside `setup.py` and import the module directly.\n\n```py\nimport setuptools\nfrom setupbase import wrap_installers, npm_builder\nfunc = npm_builder()\ncmdclass = wrap_installers(post_develop=func, pre_dist=func)\nsetup(cmdclass=cmdclass)\n```\n\n## Usage Notes\n\n- This package does not work with the deprecated `python setup.py bdist_wheel` or `python setup.py sdist` commands, PyPA recommends using the [build](https://pypa-build.readthedocs.io/en/latest/index.html) package (`pip install build && python -m build .`).\n- We recommend using `include_package_data=True` and `MANIFEST.in` to control the assets included in the [package](https://setuptools.readthedocs.io/en/latest/userguide/datafiles.html).\n- Tools like [`check-manifest`](https://github.com/mgedmin/check-manifest) or [`manifix`](https://github.com/vidartf/manifix) can be used to ensure the desired assets are included.\n- Simple uses of `data_files` can be handled in `setup.cfg` or in `setup.py`.  If recursive directories are needed use `get_data_files()` from this package.\n- Unfortunately `data_files` are not supported in `develop` mode (a limitation of `setuptools`).  You can work around it by doing a full install (`pip install .`) before the develop install (`pip install -e .`), or by adding a script to push the data files to `sys.base_prefix`.\n\n## Development Install\n\n```bash\ngit clone https://github.com/jupyter/jupyter-packaging.git\ncd jupyter-packaging\npip install -e .[test]\npre-commit install\n```\n\nYou can test changes locally by creating a `pyproject.toml` with the following, replacing the local path to the git checkout:\n\n```toml\n[build-system]\nrequires = ["jupyter_packaging@file://<path-to-git-checkout>"]\nbuild-backend = "setuptools.build_meta"\n```\n\nNote: you need to run `pip cache remove jupyter_packaging` any time changes are made to prevent `pip` from using a cached version of the source.\n',
    author_email='Jupyter Development Team <jupyter@googlegroups.com>',
    classifiers=[
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    install_requires=[
        'deprecation',
        'packaging',
        'setuptools>=60.2.0',
        'tomlkit',
        'wheel',
    ],
    extras_require={
        'test': [
            'build',
            'coverage',
            'pre-commit',
            'pytest',
            'pytest-cov',
            'pytest-mock',
            'pytest-timeout',
        ],
    },
    packages=[
        'jupyter_packaging',
    ],
)
