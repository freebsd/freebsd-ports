# New ports collection makefile for:	pipenightdreams
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	pipenightdreams
PORTVERSION=	0.6.1
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/package/

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"

pre-patch:
	@${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g; s|SDL_LIBSS|SDL_LIBS|g;' ${WRKSRC}/configure
	@find ${WRKSRC} -name Makefile.in | \
		xargs ${PERL} -pi -e 's|/games/|/|g'
	@${PERL} -pi -e "s|/usr/local/share/games|${LOCALBASE}/share|g" ${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
