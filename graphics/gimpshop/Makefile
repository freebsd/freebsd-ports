# New ports collection makefile for:    Gimp
# Version required:     0.99.14
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.15 1997/12/16 23:25:34 erich Exp $
#

MAJOR=	0
MINOR=	99
MICRO=	16

VERSION=		${MAJOR}.${MINOR}.${MICRO}
MM_VERSION= ${MAJOR}.${MINOR}

DISTNAME=   gimp-${VERSION}
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	gimp-data-min-${MM_VERSION}.tar.gz \
            gimp-data-extras-${MM_VERSION}.tar.gz

CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.gimp.org/pub/gimp/0.99/${VERSION}/ \
                ftp://ftp.cs.umn.edu/pub/gimp/gimp/0.99/${VERSION}/ \

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
		LIBS=-L${LOCALBASE}/lib INSTALL_SCRIPT='$${INSTALL} -m 755'
CONFIGURE_ARGS=  --with-tcl=tcl80 --with-tk=tk80

DATASTUFF=  brushes palettes gradients patterns

post-install:
	mkdir -p ${PREFIX}/share/gimp/;
	cd ${WRKDIR}/gimp-data-min-${MM_VERSION}; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/; tar -xvf -)
	cd ${WRKDIR}/gimp-data-extras-${MM_VERSION}; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/; tar -xvf -)

post-extract:
	rm -f ${WRKSRC}/plug-ins/gimptcl/scripts/consolio \
		${WRKSRC}/plug-ins/gimptcl/scripts/pdb_help \
		${WRKSRC}/plug-ins/gimptcl/scripts/stained_glass

.include <bsd.port.mk>

