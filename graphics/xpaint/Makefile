# New ports collection makefile for:    xpaint
# Version required:     2.5.3
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.16 1997/12/01 07:59:32 tg Exp $
#

DISTNAME=       xpaint-2.5.3
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm   \
		png\\.0\\.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes

.include <bsd.port.mk>
