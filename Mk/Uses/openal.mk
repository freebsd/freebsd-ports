# $FreeBSD$
#
# Handle dependency on OpenAL
#
# Feature:	openal
# Usage:	USES=openal or USES=openal:ARGS
# Valid ARGS:	al, soft (default), alut
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_OPENAL_MK)
_INCLUDE_USES_OPENAL_MK=	yes

.if empty(openal_ARGS)
openal_ARGS=	soft
.endif

.if !empty(openal_ARGS:Nal:Nsoft:Nalut)
IGNORE=	has unknown USES=openal arguments: ${openal_ARGS:Nal:Nsoft:Nalut}
.endif

_OPENAL_al_DEPENDS=	libopenal.so.1:audio/openal-soft
_OPENAL_soft_DEPENDS=	libopenal.so.1:audio/openal-soft
_OPENAL_alut_DEPENDS=	libalut.so.0:audio/freealut

.for _arg in ${openal_ARGS}
LIB_DEPENDS+=	${_OPENAL_${_arg}_DEPENDS}
.endfor

.endif
