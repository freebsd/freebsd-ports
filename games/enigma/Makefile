# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	0.60
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/enigma/

MAINTAINER=	edwin@mavetju.org

BUILD_DEPENDS=	${LOCALBASE}/bin/sdl11-config:${PORTSDIR}/devel/sdl12 \
		lua:${PORTSDIR}/lang/lua
LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer	\
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

MAN6=		enigma.6

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
