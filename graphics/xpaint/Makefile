# New ports collection makefile for:    xpaint
# Version required:     2.5.2
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp $
#

DISTNAME=       xpaint-2.5.2
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm   \
		png\\.0\\.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes

.include <bsd.port.mk>
