# New ports collection makefile for:    Gimp
# Version required:     1.0.1
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.47 1998/09/23 00:51:58 vanilla Exp $
#

DISTNAME=	gimp-1.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.0/v1.0.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.0/v1.0.1/ \
		http://www.ameth.org/gimp/pub/gimp/v1.0/v1.0.1/
DISTFILES=	gimp-1.0.1.tar.gz gimp-data-extras-1.0.0.tar.gz

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gtk.1:${PORTSDIR}/x11-toolkits/gtk
LIB_DEPENDS+=	mpeg.1:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	png.2:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	tiff34.1:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS+=	xdelta.0:${PORTSDIR}/misc/xdelta

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-xdelta=yes
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
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
