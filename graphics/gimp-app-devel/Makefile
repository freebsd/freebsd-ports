# New ports collection makefile for:    Gimp
# Version required:     1.1.2
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.52 1999/01/23 07:05:22 vanilla Exp $
#

DISTNAME=	gimp-1.1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/unstable/v1.1.2/ \
		http://www.ameth.org/gimp/pub/gimp/unstable/v1.1.2/

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel \
		mpeg.1:${PORTSDIR}/graphics/mpeg-lib \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-perl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib" \
		INSTALL_SCRIPT='$${INSTALL} -m 755'

MAN1=		gimp.1 gimptool.1
MAN3=		gpc.3

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
