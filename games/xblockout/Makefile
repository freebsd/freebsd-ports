# New ports collection makefile for:	xwelltris
# Date created:		1 Feb 2004
# Whom:			lev
#
# $FreeBSD$
#

PORTNAME=	xblockout
PORTVERSION=	1.1.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp710.univ-lyon1.fr/pub/xbl/
DISTNAME=	xbl-${PORTVERSION}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	BlockOut, 3D tetris-like game

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CPP=${CPP}"
USE_XLIB=	yes
USE_X_PREFIX=	yes

PLIST_FILES=	bin/xbl \
		lib/X11/app-defaults/Xbl \
		lib/X11/xbl/COPYING \
		lib/X11/xbl/Xbl \
		lib/X11/xbl/xbl-game.gif \
		lib/X11/xbl/xbl-man.html \
		lib/X11/xbl/xbl-menu.gif \
		lib/X11/xbl/xbl-score.gif \
		lib/X11/xbl/xbl-zoo.gif \
		lib/X11/xbl/xbl.html
PKG_DIRS=	lib/X11/xbl
MAN6=		xbl.6

.include <bsd.port.mk>
