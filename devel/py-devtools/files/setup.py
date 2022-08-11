# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='devtools',
    version='%%PORTVERSION%%',
    description="Python's missing debug print command, and more.",
    long_description="# python devtools\n\n[![CI](https://github.com/samuelcolvin/python-devtools/workflows/CI/badge.svg?event=push)](https://github.com/samuelcolvin/python-devtools/actions?query=event%3Apush+branch%3Amain+workflow%3ACI)\n[![Coverage](https://codecov.io/gh/samuelcolvin/python-devtools/branch/main/graph/badge.svg)](https://codecov.io/gh/samuelcolvin/python-devtools)\n[![pypi](https://img.shields.io/pypi/v/devtools.svg)](https://pypi.python.org/pypi/devtools)\n[![versions](https://img.shields.io/pypi/pyversions/devtools.svg)](https://github.com/samuelcolvin/python-devtools)\n[![license](https://img.shields.io/github/license/samuelcolvin/python-devtools.svg)](https://github.com/samuelcolvin/python-devtools/blob/main/LICENSE)\n\n**Python's missing debug print command and other development tools.**\n\nFor more information, see [documentation](https://python-devtools.helpmanual.io/).\n\n## Install\n\nJust\n\n```bash\npip install devtools[pygments]\n```\n\n`pygments` is not required but if it's installed, output will be highlighted and easier to read.\n\n`devtools` has no other required dependencies except python 3.7, 3.8, 3.9 or 3.10.\nIf you've got python 3.7+ and `pip` installed, you're good to go.\n\n## Usage\n\n```py\nfrom devtools import debug\n\nwhatever = [1, 2, 3]\ndebug(whatever)\n```\n\nOutputs:\n\n```py\ntest.py:4 <module>:\n    whatever: [1, 2, 3] (list)\n```\n\n\nThat's only the tip of the iceberg, for example:\n\n```py\nimport numpy as np\n\ndata = {\n    'foo': np.array(range(20)),\n    'bar': {'apple', 'banana', 'carrot', 'grapefruit'},\n    'spam': [{'a': i, 'b': (i for i in range(3))} for i in range(3)],\n    'sentence': 'this is just a boring sentence.\\n' * 4\n}\n\ndebug(data)\n```\n\noutputs:\n\n![python-devtools demo](https://raw.githubusercontent.com/samuelcolvin/python-devtools/main/demo.py.png)\n\n## Usage without Import\n\ndevtools can be used without `from devtools import debug` if you add `debug` into `__builtins__`\nin `sitecustomize.py`.\n\nFor instructions on adding `debug` to `__builtins__`, \nsee the [installation docs](https://python-devtools.helpmanual.io/usage/#usage-without-import).\n",
    author_email='Samuel Colvin <s@muelcolvin.com>',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Environment :: Console',
        'Environment :: MacOS X',
        'Intended Audience :: Developers',
        'Intended Audience :: Education',
        'Intended Audience :: Information Technology',
        'Intended Audience :: Science/Research',
        'Intended Audience :: System Administrators',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux',
        'Operating System :: Unix',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Topic :: Internet',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Typing :: Typed',
    ],
    install_requires=[
        'asttokens<3.0.0,>=2.0.0',
        'executing<1.0.0,>=0.8.0',
    ],
    extras_require={
        'pygments': [
            'pygments>=2.2.0',
        ],
    },
    packages=[
        'devtools',
        'tests',
    ],
)
