# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdlmm
PORTVERSION=	0.1.8
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/SDLmm/${PORTVERSION}
DISTNAME=	SDLmm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Wrapper for the SDL (Simple DirectMedia Layer)

USES=		libtool
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDLmm.so

.include <bsd.port.mk>
