# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clunk
PORTVERSION=	1.2.130
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/clunk

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Real-time 3D sound generation library

USES=		tar:bzip2 cmake
USE_SDL=	sdl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SSE
OPTIONS_DEFAULT_amd64=SSE
SSE_CMAKE_ON=	-DWITH_SSE:BOOL=TRUE

.include <bsd.port.mk>
