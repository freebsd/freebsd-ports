# $FreeBSD$
#
# Provide support to use the scons
#
# Feature:		scons
# Usage:		USES=scons
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_SCONS_MK)
_INCLUDE_USES_SCONS_MK=	yes

.if !empty(scons_ARGS)
IGNORE=	Incorrect 'USES+= scons:${scons_ARGS}' scons takes no arguments
.endif

MAKEFILE=		#
MAKE_FLAGS=		#
ALL_TARGET=		#
CCFLAGS?=		${CFLAGS}
LINKFLAGS?=		${LDFLAGS}
LIBPATH?=		${LOCALBASE}/lib
CPPPATH?=		${LOCALBASE}/include
SCONS=			${LOCALBASE}/bin/scons
BUILD_DEPENDS+=		${SCONS}:${PORTSDIR}/devel/scons
MAKE_CMD=		${SCONS}
MAKE_ARGS+=	CCFLAGS="${CCFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		LINKFLAGS="${LINKFLAGS}" PKGCONFIGDIR="${PKGCONFIGDIR}"  \
		CPPPATH="${CPPPATH}" LIBPATH="${LIBPATH}" PREFIX="${PREFIX}" \
		CC="${CC}" CXX="${CXX}" ${DESTDIRNAME:tl}=${STAGEDIR}

.endif
