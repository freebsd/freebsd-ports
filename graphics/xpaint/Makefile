# New ports collection makefile for:    xpaint
# Version required:     2.5.6
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.33 1999/01/09 00:28:21 fenner Exp $
#

DISTNAME=       xpaint-2.5.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.image.dk/~torsten/xpaint/ \
		ftp://ftp.win.or.jp/pub/graphics/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		Xpm.4:${PORTSDIR}/graphics/xpm   \
		png.3:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes
MAN1=		xpaint.1

.include <bsd.port.mk>
