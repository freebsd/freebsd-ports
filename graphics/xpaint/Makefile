# New ports collection makefile for:    xpaint
# Version required:     2.1.1
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.3 1995/01/13 13:14:24 jkh Exp $
#

DISTNAME=       xpaint-2.1.1
MASTER_SITES=	ftp://romulus.ucs.uoknor.edu/X/R5contrib/
LIB_DEPENDS=	jpeg\\.5\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
USE_IMAKE=      yes
WRKSRC=		${.CURDIR}/work/xpaint

.include <bsd.port.mk>
