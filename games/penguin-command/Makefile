# New ports collection makefile for:	penguin-command
# Date created:			Apr 4, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	penguin-command
PORTVERSION=	1.6.2
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/penguin-command/

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		png.5:${PORTSDIR}/graphics/png

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"
MAN6=		penguin-command.6

post-patch:
	${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g' \
		${WRKSRC}/configure ${WRKSRC}/src/*.[ch]
	${PERL} -pi -e "s/ -lz -lSDL -lm/ -lz -lm/g" ${WRKSRC}/configure

.include <bsd.port.mk>
