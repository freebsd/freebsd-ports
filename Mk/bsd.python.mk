# -*- mode: Fundamental; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

Python_Include=				bsd.python.mk
Python_Include_MAINTAINER=	tg@FreeBSD.org

# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the Python
# language. It's automatically included when USE_PYTHON or PYTHON_VERSION
# is defined in the ports' makefile. Define PYTHON_VERSION to override the
# defaults that USE_PYTHON would give you.
#
# The variables:
#
# PYTHON_CMD:	Python's command line file name, including the version
#				number (used for dependencies), but not using the full path.
#				default: depends on the version of your python binary
#
# PYTHON_DISTFILE:	The ${DISTFILE} for your python version. Needed for
#					extensions like Tkinter, py-gdbm and py-expat, which
#					are built from sources contained in the Python
#					distribution.
#
# PYTHON_LIBDIR:	Base of the python library tree
#					default: ${LOCALBASE}/lib/python${PYVERSION}
#
# PYTHON_PORTSDIR:	The source of your binary's port. Needed for the
#					RUN_DEPENDS.
#
# PYTHON_PORTVERSION:	Version number suitable for ${PORTVERSION}.
#
# PYTHON_SITELIBDIR:	Location of the site-packages tree. Don't change,
#					unless you know what you do.
#						default: ${PYTHON_LIBDIR}/site-packages
#
# PYTHON_VERSION:	Version of the python binary in your ${PATH}, in the 
#					format "python2.0".	Set this in your makefile in case you
#					want to build extensions with an older binary.
#					default: depends on the version of your python binary
#
# PYTHON_WRKSRC:	The ${WRKSRC} for your python version. Needed for
#					extensions like Tkinter, py-gdbm and py-expat, which
#					are built from sources contained in the Python
#					distribution.
#
# PYDISTUTILS:	Dependency line for the distutils extension. As of Python-2.0,
#				the distutils are in the base distribution.
#
# PYXML:		Dependency line for the XML entension. As of Python-2.0,
#				this extension is in the base distribution.

# XXX Ugly hack, but running python is the best way to determine the
# currently installed version. If Python is not installed, a default 
# version number is substituted and the corresponding Python distribution
# will be built through the dependency processing.
_PYTHON_VERSION!=	(python -c 'import sys; print sys.version[:3]') 2> /dev/null \
					|| echo 1.6
PYTHON_VERSION?=	python${_PYTHON_VERSION}
PYTHON_PORTVERSION!=	(${PYTHON_VERSION} -c 'import string, sys; \
								print string.split(sys.version)[0]') 2> /dev/null \
					|| echo 1.6

# Python-2.0
.if ${PYTHON_VERSION} == "python2.0"
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PORTSDIR}/lang/python
PYXML=			${PYTHON_LIBDIR}/xml/xmllib.py:${PORTSDIR}/lang/python

PYTHON_DISTFILE=	BeOpen-Python-2.0b1.tar.gz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python-beta
PYTHON_WRKSRC=		${WRKDIR}/Python-2.0b1

# Python-1.6
.elif ${PYTHON_VERSION} == "python1.6"
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PORTSDIR}/misc/py-distutils
PYXML=			${PYTHON_LIBDIR}/site-packages/xml/xmllib.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	Python-1.6.tar.gz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python
PYTHON_WRKSRC=		${WRKDIR}/Python-1.6

# Python-1.5
.elif ${PYTHON_VERSION} == "python1.5"
PYDISTUTILS=	${PYTHON_LIBDIR}/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
PYXML=			${PYTHON_LIBDIR}/site-packages/xml/xmllib.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	py152.tgz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python15
PYTHON_WRKSRC=		${WRKDIR}/Python-1.5.2

.else
.BEGIN:
	@${ECHO} "Error: bad value for PYTHON_VERSION: ${PYTHON_VERSION}."
	@${ECHO} "Use one of python1.5, python1.6 (default) or python2.0." 
	@${FALSE}
.endif

PYTHON_CMD=		${PYTHON_VERSION}
PYTHON_LIBDIR=	${LOCALBASE}/lib/${PYTHON_VERSION}
PYTHON_SITELIBDIR=	${PYTHON_LIBDIR}/site-packages

# dependencies
PYTHON_NO_DEPENDS?=	NO

.if ${PYTHON_NO_DEPENDS} == "NO"
BUILD_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
.endif

# pkg/PLIST substrings
PLIST_SUB+=		PYTHON_VERSION=${PYTHON_VERSION}
