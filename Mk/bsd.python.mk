# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Python_Pre_Include)

Python_Pre_Include=			bsd.python.mk
Python_Include_MAINTAINER=	alane@FreeBSD.org

# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the Python
# language. It's automatically included when USE_PYTHON or PYTHON_VERSION
# is defined in the ports' makefile. Define PYTHON_VERSION to override the
# defaults that USE_PYTHON would give you.
#
# The variables:
#
# PYTHONBASE:	Python port's installation prefix.
#				default: ${LOCALBASE}
#
# PYTHON_CMD:	Python's command line file name, including the version
#				number (used for dependencies).
#				default: ${PYTHONBASE}/bin/${PYTHON_VERSION}
#
# PYTHON_DISTFILE:	The ${DISTFILE} for your python version. Needed for
#					extensions like Tkinter, py-gdbm and py-expat, which
#					are built from sources contained in the Python
#					distribution.
#
# PYTHON_INCLUDEDIR:	Location of the Python include files.
#						default: ${PYTHONBASE}/include/${PYTHON_VERSION}
#
# PYTHON_LIBDIR:	Base of the python library tree
#					default: ${PYTHONBASE}/lib/${PYTHON_VERSION}
#
# PYTHON_PKGNAMEPREFIX:	Use this as a ${PKGNAMEPREFIX} to distinguish
#						packages for different Python versions.
#						default: py${PYTHON_SUFFIX}-
#
# PYTHON_PLATFORM:	Python's idea of the OS release.
#					XXX This is faked with ${OPSYS} and ${OSREL} until I  
#					find out how to delay defining a variable until after 
#					a certain target has been built. 
#
# PYTHON_PORTSDIR:	The source of your binary's port. Needed for the
#					RUN_DEPENDS.
#
# PYTHON_PORTVERSION:	Version number suitable for ${PORTVERSION}.
#
# PYTHON_REL:		Version number in numerical format, to ease
#					comparison in makefiles
#
# PYTHON_SITELIBDIR:	Location of the site-packages tree. Don't change,
#					unless you know what you do.
#						default: ${PYTHON_LIBDIR}/site-packages
#
# PYTHON_SUFFIX:	Yet another short version number, primarily intended
#					for ${PYTHON_PKGNAMEPREFIX}.
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
# There are PREFIX-clean variants of the PYTHON_*DIR variables above.
# They are meant to be used in the installation targets.
#
# PYTHONPREFIX_INCLUDEDIR:	default: ${PREFIX}/include/${PYTHON_VERSION}
# PYTHONPREFIX_LIBDIR:		default: ${PREFIX}/lib/${PYTHON_VERSION}
# PYTHONPREFIX_SITELIBDIR:	default: ${PYTHONPREFIX_LIBDIR}/site-packages
#
# PYDISTUTILS:	Dependency line for the distutils extension. As of Python-2.0,
#				the distutils are in the base distribution.
#
# PYNUMERIC:	Dependency line for the numeric extension. Py-Numeric-17
# 				is the last release that works with Python versions older
#				than 1.6.
#
# PYXML:		Dependency line for the XML extension. As of Python-2.0,
#				this extension is in the base distribution.
#
# USE_PYTHON_PREFIX:	Says that the port installs in ${PYTHONBASE}.
#
# USE_PYDISTUTILS:	Use distutils as do-build and do-install target.
#
# PYDISTUTILS_BUILDARGS:	Arguments to build with distutils.
#							default: <empty>
#
# PYDISTUTILS_INSTALLARGS:	Arguments to install with distutils.
#							default: -c -O1 --prefix=${PREFIX}
#
# PYSETUP:		Name of the setup script used by the distutils package.
#				default: setup.py

# Determine the currently installed version. If Python is not installed, a
# default version number is substituted and the corresponding Python
# distribution will be built through the dependency processing.
.if defined(PYTHON_CMD)
_PYTHON_VERSION!=	${PYTHON_CMD} -c 'import sys; print sys.version[:3]'
.elif defined(USE_ZOPE)
_PYTHON_VERSION=	2.1
.else
_PYTHON_VERSION!=	(python -c 'import sys; print sys.version[:3]') 2> /dev/null \
					|| echo 2.2
.endif
PYTHON_VERSION?=	python${_PYTHON_VERSION}
_PYTHON_PORTVERSION=	2.2.2
PYTHON_PORTVERSION!=	(${PYTHON_VERSION} -c 'import string, sys; \
								print string.split(sys.version)[0]') 2> /dev/null \
					|| echo ${_PYTHON_PORTVERSION}
PYTHONBASE!=		(${PYTHON_VERSION} -c 'import sys; print sys.prefix') \
						2> /dev/null || echo ${LOCALBASE}
PYTHON_CMD?=		${PYTHONBASE}/bin/${PYTHON_VERSION}

# Python-2.2
.if ${PYTHON_VERSION} == "python2.2"
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PYTHON_PORTSDIR}
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
PYXML=			${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	Python-${_PYTHON_PORTVERSION}.tgz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python
PYTHON_REL=			222
PYTHON_SUFFIX=		22
PYTHON_WRKSRC=		${WRKDIR}/Python-${_PYTHON_PORTVERSION}

# Python-2.1
.elif ${PYTHON_VERSION} == "python2.1"
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PYTHON_PORTSDIR}
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
PYXML=			${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	Python-2.1.3.tgz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python21
PYTHON_REL=			213
PYTHON_SUFFIX=		21
PYTHON_WRKSRC=		${WRKDIR}/Python-2.1.3

# Python-2.0
.elif ${PYTHON_VERSION} == "python2.0"
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PYTHON_PORTSDIR}
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
PYXML=			${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	Python-2.0.1.tgz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python20
PYTHON_REL=			201
PYTHON_SUFFIX=		20
PYTHON_WRKSRC=		${WRKDIR}/Python-2.0.1

# Python-1.6
# ${PYTHON_PORTSDIR} is not set because we don't support building 
# Python-1.6 from the ports anymore. People should use the
# latest version in ${PORTSDIR}/lang/python. The definitions here
# are for those who still have 1.6 as their default version.
.elif ${PYTHON_VERSION} == "python1.6"
PYDISTUTILS=	${PYTHON_LIBDIR}/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric17
PYXML=			${PYTHON_SITELIBDIR}/xml/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	Python-1.6.tar.gz
PYTHON_PORTSDIR=	# empty
PYTHON_REL=			160
PYTHON_SUFFIX=		16
PYTHON_WRKSRC=		${WRKDIR}/Python-1.6

# Python-1.5
.elif ${PYTHON_VERSION} == "python1.5"
PYDISTUTILS=	${PYTHON_LIBDIR}/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric17
PYXML=			${PYTHON_SITELIBDIR}/xml/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	py152.tgz
PYTHON_PORTSDIR=	${PORTSDIR}/lang/python15
PYTHON_REL=			152
PYTHON_SUFFIX=		15
PYTHON_WRKSRC=		${WRKDIR}/Python-1.5.2

# Python versions in development
.elif defined(FORCE_PYTHON_VERSION)
PYDISTUTILS=	${PYTHON_LIBDIR}/distutils/core.py:${PYTHON_PORTSDIR}
PYNUMERIC=		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
PYXML=			${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

PYTHON_DISTFILE=	# empty
PYTHON_PORTSDIR=	# empty
PYTHON_NO_DEPENDS=	YES
PYTHON_REL!=		${PYTHON_CMD} -c 'import sys; h = "%x" % sys.hexversion; \
						print h[0]+h[2]+h[4]'
PYTHON_SUFFIX!=		${PYTHON_CMD} -c 'import sys; h = "%x" % sys.hexversion; \
						print h[0]+h[2]'
PYTHON_WRKSRC=		${WRKDIR}/Python-${_PYTHON_PORTVERSION}

.else
.BEGIN:
	@${ECHO} "Error: bad value for PYTHON_VERSION: ${PYTHON_VERSION}."
	@${ECHO} "Legal values are:"
	@${ECHO} "  python1.5"
	@${ECHO} "  python1.6"
	@${ECHO} "  python2.0"
	@${ECHO} "  python2.1"
	@${ECHO} "  python2.2 (default)."
	@${FALSE}
.endif

PYTHON_INCLUDEDIR=		${PYTHONBASE}/include/${PYTHON_VERSION}
PYTHON_LIBDIR=			${PYTHONBASE}/lib/${PYTHON_VERSION}
PYTHON_PKGNAMEPREFIX=	py${PYTHON_SUFFIX}-
PYTHON_PLATFORM!=		expr ${OPSYS:L}${OSREL} : '\(.*\)\.'
PYTHON_SITELIBDIR=		${PYTHON_LIBDIR}/site-packages

PYTHONPREFIX_INCLUDEDIR=	${PYTHON_INCLUDEDIR:S;${PYTHONBASE};${PREFIX};}
PYTHONPREFIX_LIBDIR=		${PYTHON_LIBDIR:S;${PYTHONBASE};${PREFIX};}
PYTHONPREFIX_SITELIBDIR=	${PYTHON_SITELIBDIR:S;${PYTHONBASE};${PREFIX};}

PYSETUP?=				setup.py
PYDISTUTILS_BUILDARGS?=
PYDISTUTILS_INSTALLARGS?=	-c -O1 --prefix=${PREFIX}

# Zope specific variables
.if defined(USE_ZOPE)
# You can change this in the environment if you like
SZOPEBASEDIR?=			www/Zope
# Don't change these. You'll probably want to define ZOPEPRODUCTNAME,
# too, but that is port-specific.
ZOPEBASEDIR=			${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTDIR=			lib/python/Products
.endif

# dependencies
PYTHON_NO_DEPENDS?=		NO

.if ${PYTHON_NO_DEPENDS} == "NO"
BUILD_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}

.if defined(USE_PYDISTUTILS) && defined(PYTHON_REL) && ${PYTHON_REL} < 200
BUILD_DEPENDS+=	${PYDISTUTILS}
.endif
.endif		# ${PYTHON_NO_DEPENDS} == "NO"

.if defined(USE_ZOPE)
RUN_DEPENDS+=	${PYTHONBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope
.endif

# set $PREFIX as Python's one
.if defined(USE_PYTHON_PREFIX)
PREFIX=			${PYTHONBASE}
.endif

# Substitutions for pkg-plist
# Use a short form of the PYTHONPREFIX_*DIR variables; we don't need the
# base directory in the plist file.
PLIST_SUB+=		PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR:S;${PREFIX}/;;} \
				PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;} \
				PYTHON_PLATFORM=${PYTHON_PLATFORM} \
				PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} \
				PYTHON_VERSION=${PYTHON_VERSION}

# Zope specific substitutions
.if defined(USE_ZOPE)
PLIST_SUB+=		ZOPEBASEDIR=${SZOPEBASEDIR}
.endif

# XXX Hm, should I export some of the variables above to *_ENV?

.endif		# !defined(_POSTMKINCLUDED) && !defined(Python_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Python_Post_Include)

Python_Post_Include=			bsd.python.mk

# py-distutils support
.if defined(USE_PYDISTUTILS)
.if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build ${PYDISTUTILS_BUILDARGS})
.endif

.if !target(do-install)
do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install ${PYDISTUTILS_INSTALLARGS})
.endif
.endif		# defined(USE_PYDISTUTILS)

.endif		# defined(_POSTMKINCLUDED) && !defined(Python_Post_Include)
