# New ports collection makefile for:	vitetris
# Date created:		2008-09-22
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vitetris
PORTVERSION=	0.56
CATEGORIES=	games
MASTER_SITES=	http://victornils.net/tetris/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Terminal-based tetris clone in vein of nintendo tetris

HAS_CONFIGURE=	yes
ALL_TARGET=	#
CONFIGURE_ARGS=	--prefix=${PREFIX} --datarootdir=${PREFIX}/share \
		curses="-lncurses" xlib=no

PLIST_FILES=	bin/vitetris \
		share/allegro/licence.txt \
		share/allegro/README \
		share/pixmaps/vitetris.xpm \
		share/applications/vitetris.desktop
PLIST_DIRS=	share/allegro \
		share/applications

post-patch:
	@${REINPLACE_CMD} -e 's,docdir,datadir,g' \
	    ${WRKSRC}/Makefile

.include <bsd.port.mk>
