# New ports collection makefile for:    xcdplayer
# Date created:		30 Sep 1994
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xcdplayer
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD player for X

USE_IMAKE=	yes
MAN1=		xcdplayer.1

PLIST_FILES=	bin/xcdplayer lib/X11/app-defaults/XCdplayer

post-extract:
	${CP} ${FILESDIR}/cdrom_freebsd.[ch] ${FILESDIR}/app.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include <bsd.port.mk>
