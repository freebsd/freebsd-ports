# $FreeBSD$
#
# Provide support to use Ninja
#
# Feature:		ninja
# Usage:		USES=ninja
#
# User defined variables:
# NINJA_VERBOSE		- Enable verbose output.
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_NINJA_MK)
_INCLUDE_USES_NINJA_MK=	yes

.if defined(ninja_ARGS)
IGNORE=	Incorrect 'USES+= ninja:${ninja_ARGS}' ninja takes no arguments
.endif

.if defined(NINJA_VERBOSE)
MAKE_ARGS+=	-v
.endif

BUILD_DEPENDS+=	ninja:${PORTSDIR}/devel/ninja

CMAKE_ARGS+=	-GNinja
MAKEFILE=
MAKE_CMD=	ninja
MAKE_FLAGS=
_DESTDIR_VIA_ENV=	yes

.endif
