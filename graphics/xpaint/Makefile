# New ports collection makefile for:	xpaint
# Version required:	2.5.7
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

DISTNAME=	xpaint-2.5.7
CATEGORIES=	graphics
MASTER_SITES=	http://home.worldonline.dk/~torsten/xpaint/ \
		ftp://ftp.win.ne.jp/pub/graphics/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Xpm.4:${PORTSDIR}/graphics/xpm   \
		png.3:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=	yes
MAN1=		xpaint.1

.include <bsd.port.mk>
