# New ports collection makefile for:    GIMP
# Version required:     961001
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.1.1.1 1996/08/24 18:32:45 chuckr Exp $
#

DISTNAME=       gimp-devel
PKGNAME=        gimp-devel-96.10.01
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.xcf.berkeley.edu/pub/gimp/developers/
DISTFILES=	gimp961001.tgz

MAINTAINER=     erich@FreeBSD.org

LIB_DEPENDS+=	png\\.0\\.[7-9]:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff\\.3\\.:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
