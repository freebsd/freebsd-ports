# $FreeBSD$
#
# Provide support to use the scons
#
# Feature:	scons
# Usage:	USES=scons[:ARGS]
# Valid ARGS:	python2 python3
#
# python2:	Use default python 2.x to run scons
# python3:	Use default python 3.x to run scons (default)
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_SCONS_MK)
_INCLUDE_USES_SCONS_MK=	yes

.if empty(scons_ARGS)
scons_ARGS=	python3
.endif

.if ${scons_ARGS} == python3
_SCONS_PYTHON_VER=	${PYTHON3_DEFAULT}
.elif ${scons_ARGS} == python2
_SCONS_PYTHON_VER=	${PYTHON2_DEFAULT}
DEPRECATED?=	Uses Python 2.7 version of scons, and Python 2.7 which is EOLed upstream
EXPIRATION_DATE?=	2020-12-31
.else
IGNORE=		Incorrect 'USES+= scons:${scons_ARGS}' usage
.endif

_SCONS_PYTHON_FLAVOR=	py${_SCONS_PYTHON_VER:S|.||}

SCONS=		${LOCALBASE}/bin/scons-${_SCONS_PYTHON_VER}

BUILD_DEPENDS+=	${SCONS}:devel/scons@${_SCONS_PYTHON_FLAVOR}

ALL_TARGET?=	#
CCFLAGS?=	${CFLAGS}
CPPPATH?=	${LOCALBASE}/include
LIBPATH?=	${LOCALBASE}/lib
LINKFLAGS?=	${LDFLAGS}
MAKE_ARGS+=	CC="${CC}" \
		CCFLAGS="${CCFLAGS}" \
		CPPPATH="${CPPPATH}" \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBPATH="${LIBPATH}" \
		LINKFLAGS="${LINKFLAGS}" \
		PKGCONFIGDIR="${PKGCONFIGDIR}" \
		PREFIX="${PREFIX}" \
		destdir=${STAGEDIR}
MAKE_CMD=	${SCONS}
MAKE_FLAGS=	#
MAKEFILE=	#
.endif
