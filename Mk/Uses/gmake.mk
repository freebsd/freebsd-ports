# $FreeBSD$
#
# Provide support to use the GNU make
#
# Feature:		gmake
# Usage:		USES=gmake[:lite]
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_GMAKE_MK)
_INCLUDE_USES_GMAKE_MK=	yes

.if defined(gmake_ARGS)
.if ${gmake_ARGS} == lite
.if !exists(${LOCALBASE}/bin/gmake)
_GMAKE_EXT=	-lite
.endif
.else
IGNORE=	Incorrect 'USES+= gmake:${gmake_ARGS}' gmake has only one valid argument: lite
.endif
.endif

.if defined(DIET)
_GMAKE_EXT=	-lite
.endif

BUILD_DEPENDS+=		gmake${_GMAKE_EXT}:${PORTSDIR}/devel/gmake${_GMAKE_EXT}
CONFIGURE_ENV+=		MAKE=gmake${_GMAKE_EXT}
MAKE_CMD?=		gmake${_GMAKE_EXT}

.endif
