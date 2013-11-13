# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xbomb
PORTVERSION=	2.2a
CATEGORIES=	games
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper with a couple of grid types

USES=		pkgconfig
USE_XORG=	xaw7

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -DLOCALBASE=\"${LOCALBASE}\" \
		`pkg-config --cflags xaw7` *.c -o xbomb \
		`pkg-config --libs xaw7`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbomb ${STAGEDIR}${PREFIX}/bin/xbomb
	${INSTALL_MAN} ${WRKSRC}/xbomb.6 ${STAGEDIR}${MANPREFIX}/man/man6/xbomb.6
	${INSTALL_DATA} ${WRKSRC}/xbomb.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XBomb
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xbomb
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/X11/xbomb/xbomb3.hi
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/X11/xbomb/xbomb4.hi
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/X11/xbomb/xbomb6.hi

.include <bsd.port.mk>
