from setuptools import setup

setup(
    name = 'watchfiles',
    version = '%%PORTVERSION%%',
    description = 'Simple, modern and high performance file watching and code reload in python.',
    author = None,
    author_email = 'Samuel Colvin <s@muelcolvin.com>',
    url = 'https://github.com/samuelcolvin/watchfiles',
    packages = ['watchfiles'],
    package_data = {'': ['*']},
    install_requires = ['anyio >= 3.0.0, <4'],
    entry_points = {'console_scripts': ['watchfiles = watchfiles.cli:cli']},
    python_requires = '>= 3.7',
)
