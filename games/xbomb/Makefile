# New ports collection makefile for:    xbomb
# Date created:         20 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xbomb
PORTVERSION=	2.2a
CATEGORIES=	games
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper with a couple of grid types

USE_XORG=	xaw7

MAN6=		xbomb.6
PLIST_FILES=	bin/xbomb \
		lib/X11/app-defaults/XBomb \
		lib/X11/xbomb/xbomb3.hi \
		lib/X11/xbomb/xbomb4.hi \
		lib/X11/xbomb/xbomb6.hi
PLIST_DIRS=	lib/X11/xbomb

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -DLOCALBASE=\"${LOCALBASE}\" \
		`pkg-config --cflags xaw7` *.c -o xbomb \
		`pkg-config --libs xaw7`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbomb ${PREFIX}/bin/xbomb
	@${CHOWN} root:games ${PREFIX}/bin/xbomb
	@${CHMOD} 2755 ${PREFIX}/bin/xbomb
	${INSTALL_MAN} ${WRKSRC}/xbomb.6 ${MANPREFIX}/man/man6/xbomb.6
	${INSTALL_DATA} ${WRKSRC}/xbomb.ad ${PREFIX}/lib/X11/app-defaults/XBomb
	@${MKDIR} ${PREFIX}/lib/X11/xbomb
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb3.hi
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb4.hi
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb6.hi
	@${CHOWN} root:games ${PREFIX}/lib/X11/xbomb/xbomb?.hi
	@${CHMOD} 664 ${PREFIX}/lib/X11/xbomb/xbomb?.hi

.include <bsd.port.mk>
