# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.6.2
CATEGORIES=	graphics
MASTER_SITES=	http://home.worldonline.dk/torsten/xpaint/ \
		ftp://ftp.win.ne.jp/pub/graphics/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A simple paint program

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xpaint.1

.include <bsd.port.mk>
