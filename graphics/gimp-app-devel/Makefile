# New ports collection makefile for:    Gimp
# Version required:     0.99.14
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.12 1997/10/16 09:04:34 tg Exp $
#

VERSION=	0.99.14

DISTNAME=   gimp-${VERSION}
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	gimp-data-min-${VERSION}.tar.gz \
            gimp-data-extras-${VERSION}.tar.gz \
            gimptcl-1.0.tar.gz

CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.cs.umn.edu/pub/gimp/gimp/0.99/${VERSION}/ \
                ftp://ftp.gimp.org/pub/gimp/0.99/${VERSION}/ \
                http://www.freebsd.org/~erich/

MAINTAINER=     erich@FreeBSD.org

LIB_DEPENDS+=	gtk\\.1\\.0:${PORTSDIR}/x11/gtk
LIB_DEPENDS+=	png\\.0\\.[7-9]:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	mpeg\\.1\\.2:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	tk80\\.1\\.:${PORTSDIR}/x11/tk80

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.0 \
		  -I${LOCALBASE}/include/tk8.0 -I${LOCALBASE}/include/tiff34" \
		LIBS=-L${LOCALBASE}/lib

DATASTUFF=  brushes palettes gradients patterns

post-install:
	cd ${WRKDIR}/gimp-data-min-${VERSION}; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/${VERSION}; tar -xvf -)
	cd ${WRKDIR}/gimp-data-extras-${VERSION}; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/${VERSION}; tar -xvf -)

.include <bsd.port.mk>

