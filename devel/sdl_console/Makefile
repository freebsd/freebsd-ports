# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_console
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/sdlconsole/sdlconsole-source/sdlconsole-${PORTVERSION}
DISTNAME=	sdlconsole-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drop down console that can be easily added to any SDL application

USES=		libtool sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SDL_IMAGE
SDL_IMAGE_DESC=	SDL Image support

SDL_IMAGE_USE=	sdl=image

.include <bsd.port.mk>
