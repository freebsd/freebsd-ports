# New ports collection makefile for:    Gimp
# Version required:     1.0.0
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.36 1998/08/05 09:31:09 asami Exp $
#

DISTNAME=	gimp-1.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.0/v1.0.0/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.0/v1.0.0/ \
		http://www.ameth.org/gimp/pub/gimp/v1.0/v1.0.0/
DISTFILES=	gimp-1.0.0.tar.gz gimp-data-extras-1.0.0.tar.gz

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	aa\\.1\\.:${PORTSDIR}/graphics/aalib
LIB_DEPENDS+=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gtk\\.1\\.5:${PORTSDIR}/x11-toolkits/gtk
LIB_DEPENDS+=	mpeg\\.1\\.2:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	png\\.2\\.:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
#LIB_DEPENDS+=	xdelta\\.0\\.18:${PORTSDIR}/misc/xdelta

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tiff34" \
		LIBS=-L${LOCALBASE}/lib INSTALL_SCRIPT='$${INSTALL} -m 755'

MAN1=		gimp.1 gimptool.1
MAN3=		gpc.3

DATASTUFF=  brushes palettes gradients patterns

post-install:
	${MKDIR} ${PREFIX}/share/gimp/;
	cd ${WRKDIR}/gimp-data-extras-1.0.0; \
	tar -cf - --exclude '*Makefile*' ${DATASTUFF} |\
	(cd ${PREFIX}/share/gimp/; tar -xvf -)

.include <bsd.port.mk>
