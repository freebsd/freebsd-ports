# New ports collection makefile for:    Gimp
# Version required:     1.0.2
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.51 1998/11/25 09:01:18 asami Exp $
#

DISTNAME=	gimp-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.0/v1.0.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.0/v1.0.2/ \
		http://www.ameth.org/gimp/pub/gimp/v1.0/v1.0.2/
DISTFILES=	gimp-1.0.2.tar.gz gimp-data-extras-1.0.0.tar.gz

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10
LIB_DEPENDS+=	mpeg.1:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	png.3:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk10-config" \
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
