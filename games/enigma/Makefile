# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	0.81
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

BUILD_DEPENDS=	sdl11-config:${PORTSDIR}/devel/sdl12 \
		lua:${PORTSDIR}/lang/lua
LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer	\
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_gfx.9:${PORTSDIR}/graphics/sdl_gfx

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

MAN6=		enigma.6

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
