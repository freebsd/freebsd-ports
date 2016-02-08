# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vitetris
PORTVERSION=	0.57
CATEGORIES=	games
MASTER_SITES=	http://victornils.net/tetris/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal-based Tetris clone in vein of Nintendo Tetris

USES=		ncurses
HAS_CONFIGURE=	yes
ALL_TARGET=	#
CONFIGURE_ARGS=	--prefix=${PREFIX} --datarootdir=${PREFIX}/share \
		curses="-lncurses" xlib=no
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/vitetris \
		share/allegro/licence.txt \
		share/allegro/README \
		share/pixmaps/vitetris.xpm \
		share/applications/vitetris.desktop

post-patch:
	@${REINPLACE_CMD} -e 's,docdir,datadir,g' \
	    ${WRKSRC}/Makefile

.include <bsd.port.mk>
