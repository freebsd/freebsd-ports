# ex:ts=8
# New ports collection makefile for:	tuxpuck
# Date created:		25 April 2002
# Whom:			Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	tuxpuck
PORTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	http://www.efd.lth.se/~d00jkr/tuxpuck/

MAINTAINER=	Jan.Stocker@t-online.de

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		vorbis.2:${PORTSDIR}/audio/libvorbis

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
ALL_TARGET=	tuxpuck

MANCOMPRESSED=	yes
MAN6=	tuxpuck.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuxpuck ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/tuxpuck.6.gz ${MANPREFIX}/man/man6

.include <bsd.port.mk>
