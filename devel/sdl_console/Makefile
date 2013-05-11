# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_console
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/sdlconsole/sdlconsole-source/sdlconsole-${PORTVERSION}
DISTNAME=	sdlconsole-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A drop down console that can be easily added to any SDL application

USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SDL_IMAGE
SDL_IMAGE_DESC=	SDL Image support

post-patch:
	@${REINPLACE_CMD} -e '/objformat/s/aout/elf/' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL_IMAGE}
USE_SDL+=	image
.endif

.include <bsd.port.mk>
