PORTNAME=	sdl_console
DISTVERSION=	2.1
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF/sdlconsole/sdlconsole-source/sdlconsole-${DISTVERSION}
DISTNAME=	sdlconsole-${DISTVERSION}

MAINTAINER=	seafork@disroot.org
COMMENT=	Drop down console that can be easily added to any SDL application
WWW=		https://wacha.ch/wiki/sdlconsole/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool sdl
USE_LDCONFIG=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			SDL_IMAGE
OPTIONS_DEFAULT=		SDL_IMAGE
SDL_IMAGE_DESC=			SDL Image support
SDL_IMAGE_USE=			sdl=image
SDL_IMAGE_CONFIGURE_ENABLE=	sdlimage

.include <bsd.port.mk>
