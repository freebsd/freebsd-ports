# New ports collection makefile for:    xpaint
# Version required:     2.5.3
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.18 1998/03/28 19:57:42 ache Exp $
#

DISTNAME=       xpaint-2.5.3
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=    jpeg\\.8\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm   \
		png\\.2\\.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes

.include <bsd.port.mk>
