# Created by: Thomas Gellekum <tg@FreeBSD.org>

PORTNAME=	xbomb
PORTVERSION=	2.2b
CATEGORIES=	games
MASTER_SITES=	http://www.gedanken.org.uk/software/xbomb/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper with a couple of grid types

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig tar:tgz xorg
USE_XORG=	xaw7

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -DLOCALBASE=\"${LOCALBASE}\" \
		`pkg-config --cflags xaw7` *.c -o xbomb \
		`pkg-config --libs xaw7`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbomb ${STAGEDIR}${PREFIX}/bin/xbomb
	${INSTALL_MAN} ${WRKSRC}/xbomb.6 ${STAGEDIR}${MANPREFIX}/man/man6/xbomb.6
	${INSTALL_DATA} ${WRKSRC}/xbomb.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XBomb
	@${MKDIR} ${STAGEDIR}/var/games/xbomb
	@${TOUCH} ${STAGEDIR}/var/games/xbomb/xbomb3.hi.sample
	@${TOUCH} ${STAGEDIR}/var/games/xbomb/xbomb4.hi.sample
	@${TOUCH} ${STAGEDIR}/var/games/xbomb/xbomb6.hi.sample

.include <bsd.port.mk>
