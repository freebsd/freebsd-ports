# New ports collection makefile for:    GIMP
# Version required:     0.99.6
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.5 1997/03/02 19:44:41 erich Exp $
#

DISTNAME=       gimp-0.99.6
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.xcf.berkeley.edu/pub/gimp/developers/

MAINTAINER=     erich@FreeBSD.org

#LIB_DEPENDS+=	png\\.0\\.[7-9]:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff\\.3\\.:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes

.include <bsd.port.mk>

