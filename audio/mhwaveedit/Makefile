# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.mtek.chalmers.se/~hjormagn/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		SDL-1.1:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
