# New ports collection makefile for:    GIMP
# Version required:     0.99.7
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.7 1997/04/08 22:06:51 erich Exp $
#

VERSION=			0.99.8
DISTNAME=       gimp-${VERSION}
DISTFILES=	${DISTNAME}.tar.gz gimp-data-0.99.8.tar.gz

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

DATASTUFF=  brushes palettes gradients patterns

post-install:
	cd ${WRKDIR}/gimp-data-${VERSION}; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/${VERSION}; tar -xvf -)


.include <bsd.port.mk>

