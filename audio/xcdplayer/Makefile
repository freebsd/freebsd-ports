# Created by: swallace
# $FreeBSD$

PORTNAME=	xcdplayer
PORTVERSION=	2.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	XCONTRIB/../R5contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD player for X

USES=		imake tar:Z xorg
USE_XORG=	xbitmaps xaw

PLIST_FILES=	bin/xcdplayer lib/X11/app-defaults/XCdplayer \
		man/man1/xcdplayer.1.gz

post-extract:
	${CP} ${FILESDIR}/cdrom_freebsd.[ch] ${FILESDIR}/app.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include <bsd.port.mk>
