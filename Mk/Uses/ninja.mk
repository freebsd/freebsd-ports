# $FreeBSD$
#
# Provide support to use ninja
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	ninja
# Usage:	USES=ninja[:verbose]

.if !defined(_INCLUDE_USES_NINJA_MK)
_INCLUDE_USES_NINJA_MK=	yes

.if defined(ninja_ARGS)
.if ${ninja_ARGS} == verbose
MAKE_ARGS+=	-v
.else
IGNORE=	Incorrect aruments for 'USES+= ninja:${ninja_ARGS}' valid argument is 'verbose'
.endif
.endif

BUILD_DEPENDS=	ninja:${PORTSDIR}/devel/ninja

CMAKE_ARGS+=	-GNinja
MAKEFILE=
MAKE_CMD=	ninja
MAKE_FLAGS=
MAKE_ENV=	${DESTDIRNAME}=${STAGEDIR}
_DESTDIR_VIA_ENV=	yes

.endif
