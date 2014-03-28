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

.if defined(scons_ARGS)
IGNORE=	Incorrect 'USES+= scons:${scons_ARGS}' scons takes no arguments
.endif

MAKEFILE=		#
MAKE_FLAGS=		#
ALL_TARGET=		#
LIBPATH?=		${LOCALBASE}/lib
CPPPATH?=		${LOCALBASE}/include
SCONS=			${LOCALBASE}/bin/scons
BUILD_DEPENDS+=		${SCONS}:${PORTSDIR}/devel/scons
MAKE_CMD?=		${SCONS}
MAKE_ENV+=		PKGCONFIGDIR="${PKGCONFIGDIR}" \
			CCFLAGS="${CFLAGS}" LINKFLAGS="${LDFLAGS}" \
			LIBPATH="${LIBPATH}" CPPPATH="${CPPPATH}"
.if !defined(NO_STAGE)
MAKE_ARGS+=		${DESTDIRNAME:L}=${STAGEDIR}
.endif

.endif
