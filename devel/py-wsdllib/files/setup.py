#!/usr/bin/env python
# To use:
#	python setup.py install
#

__version__ = "$FreeBSD$"

from os import environ
from distutils.core import setup

setup(name = environ["PORTNAME"],
	version = environ["PORTVERSION"],
	description = environ["COMMENT"],
	py_modules=["wsdllib"])
