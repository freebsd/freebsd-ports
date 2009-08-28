# New ports collection makefile for:	kuklomenos
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	kuklomenos
PORTVERSION=	0.3.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mbays.freeshell.org/kuklomenos/src/ LOCAL/chinsan/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but challenging abstract shoot-em-up game

USE_SDL=	sdl gfx

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` `freetype-config --cflags` -I${LOCALBASE}/include " \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib"

PLIST_FILES=	bin/kuklomenos %%DATADIR%%/10x20.fnt %%DATADIR%%/7x13.fnt \
		%%DATADIR%%/amiga_machines.mod
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
