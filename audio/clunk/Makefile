# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clunk
PORTVERSION=	1.3.261
CATEGORIES=	audio
MASTER_SITES=	SF/clunk

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Real-time 3D sound generation library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake sdl tar:bzip2
USE_SDL=	sdl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SSE
OPTIONS_DEFAULT_amd64=SSE
SSE_CMAKE_ON=	-DWITH_SSE:BOOL=TRUE

.include <bsd.port.mk>
