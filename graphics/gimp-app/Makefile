# New ports collection makefile for:    Gimp
# Version required:     0.99.28
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.30 1998/05/04 20:22:36 jseger Exp $
#

MAJOR=	0
MINOR=	99
MICRO=	28

VERSION=	${MAJOR}.${MINOR}.${MICRO}
MM_VERSION=	${MAJOR}.${MINOR}

DISTNAME=	gimp-${VERSION}
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	gimp-data-extras-${MM_VERSION}a.tar.gz

CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v${MAJOR}.${MINOR}/v${VERSION}/ \
	ftp://ftp.cs.umn.edu/pub/gimp/gimp/v${MAJOR}.${MINOR}/v${VERSION}/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	aa\\.1\\.:${PORTSDIR}/graphics/aalib
LIB_DEPENDS+=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gtk\\.1:${PORTSDIR}/x11/gtk
LIB_DEPENDS+=	mpeg\\.1\\.2:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	png\\.2\\.:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS+=	xdelta\\.0:${PORTSDIR}/misc/xdelta

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tiff34" \
		LIBS=-L${LOCALBASE}/lib INSTALL_SCRIPT='$${INSTALL} -m 755'

MAN1=		gimp.1

DATASTUFF=  brushes palettes gradients patterns

post-install:
	mkdir -p ${PREFIX}/share/gimp/;
	cd ${WRKDIR}/gimp-data-extras-${MM_VERSION}a; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/; tar -xvf -)

.include <bsd.port.mk>
