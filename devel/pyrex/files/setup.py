from distutils.core import setup

setup(
    name = 'pyrex',
    version = "%%PORTVERSION%%",
    packages = ['Pyrex', 'Pyrex.Compiler', 'Pyrex.Mac'],
    scripts = ['pyrexc'],
    )
