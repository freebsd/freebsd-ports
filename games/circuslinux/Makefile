# New ports collection makefile for:	circuslinux
# Date created:				1 March 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	circuslinux
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	http://www.nbswebfx.com/downloads/

MAINTAINER=	edwin@mavetju.org
COMMENT=	"Circus Linux!" is a clone of the Atari 2600 game "Circus Atari"

BUILD_DEPENDS=	sdl11-config:${PORTSDIR}/devel/sdl12
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
USE_XLIB=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.mk>
