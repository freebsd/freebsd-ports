# New ports collection makefile for:    xpaint
# Version required:     2.5.4
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.27 1998/09/19 05:46:06 steve Exp $
#

DISTNAME=       xpaint-2.5.4
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff34.1:${PORTSDIR}/graphics/tiff34 \
		Xpm.4:${PORTSDIR}/graphics/xpm   \
		png.2:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes
MAN1=		xpaint.1

.include <bsd.port.mk>
