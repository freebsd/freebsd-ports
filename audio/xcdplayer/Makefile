# Created by: swallace
# $FreeBSD$

PORTNAME=	xcdplayer
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	XCONTRIB/../R5contrib
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD player for X

USES=		imake
USE_XORG=	xbitmaps xaw
MAKE_JOBS_SAFE=	yes

MAN1=		xcdplayer.1

PLIST_FILES=	bin/xcdplayer lib/X11/app-defaults/XCdplayer

post-extract:
	${CP} ${FILESDIR}/cdrom_freebsd.[ch] ${FILESDIR}/app.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include <bsd.port.mk>
