# $FreeBSD$
#
# Provide support to use the scons
#
# Feature:	scons
# Usage:	USES=scons
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_SCONS_MK)
_INCLUDE_USES_SCONS_MK=	yes

.if !empty(scons_ARGS)
IGNORE=	Incorrect 'USES+= scons:${scons_ARGS}' scons takes no arguments
.endif

SCONS=		${LOCALBASE}/bin/scons

BUILD_DEPENDS+=	${SCONS}:devel/scons

ALL_TARGET=	#
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
