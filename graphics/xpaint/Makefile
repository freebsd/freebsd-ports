# New ports collection makefile for:    xpaint
# Version required:     2.4.3
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.7 1995/10/03 21:58:37 ache Exp $
#

DISTNAME=       xpaint-2.4.3
CATEGORIES+=	graphics x11
MASTER_SITES=	http://www2.dk-online.dk/users/Torsten_Martinsen/xpaint/

LIB_DEPENDS=    jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes

.include <bsd.port.mk>
