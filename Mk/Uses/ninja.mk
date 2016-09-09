# $FreeBSD$
#
# Provide support to use Ninja
#
# Feature:		ninja
# Usage:		USES=ninja
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_NINJA_MK)
_INCLUDE_USES_NINJA_MK=	yes

.if !empty(ninja_ARGS)
IGNORE=	Incorrect 'USES+= ninja:${ninja_ARGS}' ninja takes no arguments
.endif

MAKE_ARGS+=	-v

BUILD_DEPENDS+=	ninja:devel/ninja

CMAKE_ARGS+=	-GNinja
MAKEFILE=
MAKE_CMD=	ninja
MAKE_FLAGS=
# Set a minimal job of 1
_MAKE_JOBS=	-j${MAKE_JOBS_NUMBER}
_DESTDIR_VIA_ENV=	yes

.endif
