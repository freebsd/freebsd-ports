# New ports collection makefile for:	penguin-command
# Date created:			Apr 4, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	penguin-command
PORTVERSION=	1.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/penguin-command/

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		png.4:${PORTSDIR}/graphics/png

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"
MAN6=		penguin-command.6

pre-patch:
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" -or \
		-name configure \) | \
		xargs ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

.include <bsd.port.mk>
