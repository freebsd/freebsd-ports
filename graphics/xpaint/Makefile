# New ports collection makefile for:    xpaint
# Version required:     2.1.1
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.5 1995/04/01 12:46:10 jkh Exp $
#

DISTNAME=       xpaint-2.1.1
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://romulus.ucs.uoknor.edu/X/R5contrib/

LIB_DEPENDS=	jpeg\\.5\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${.CURDIR}/work/xpaint
USE_IMAKE=      yes

.include <bsd.port.mk>
