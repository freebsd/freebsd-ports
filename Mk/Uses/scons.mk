# Provide support to use the scons
#
# Feature:	scons
# Usage:	USES=scons
# Valid ARGS:	none
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_SCONS_MK)
_INCLUDE_USES_SCONS_MK=	yes

.  if !empty(scons_ARGS)
IGNORE+=	USES=scons takes no arguments
.  endif

_SCONS_PYTHON_VER=	${PYTHON_DEFAULT}

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
