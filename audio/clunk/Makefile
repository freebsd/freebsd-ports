# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clunk
PORTVERSION=	1.2.130
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/clunk

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Real-time 3D sound generation library

USE_BZIP2=	yes
USES=		cmake
USE_SDL=	sdl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SSE
OPTIONS_DEFAULT_amd64=SSE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSE}
CMAKE_ARGS+=	-DWITH_SSE:BOOL=TRUE
.endif

.include <bsd.port.mk>
