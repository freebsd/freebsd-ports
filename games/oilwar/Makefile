# New ports collection makefile for:	oilwar
# Date created:				18 April 2003
# Whom:				Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	oilwar
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.2ndpoint.fi/projektit/filut/
DISTNAME=	OilWar-${PORTVERSION}

MAINTAINER=	hendrik@scholz.net
COMMENT=	Evil army wants to steal your oil

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.mk>
