# New ports collection makefile for:	pipenightdreams
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	pipenightdreams
PORTVERSION=	0.10.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/packages/

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"

MAN6=		pipenightdreams.6

pre-patch:
	@${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g; \
		s|SDL_LIBSS|SDL_LIBS|g; s|datadir/games|datadir|;' \
		${WRKSRC}/configure
	@find ${WRKSRC} -name Makefile.in | \
		xargs ${PERL} -pi -e 's|/games/|/|g; \
			s/^pipenightdreams_LDADD.+//g;'
	@${PERL} -pi -e "s|/usr/share/games|${LOCALBASE}/share|g" ${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
