# New ports collection makefile for:    Gimp
# Version required:     1.1.11
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	gimp-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/unstable/v${VERSION}/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/unstable/v${VERSION}/ \
		http://www.ameth.org/gimp/pub/gimp/unstable/v${VERSION}/ \
		ftp://ftp.gimp.org/pub/gimp/unstable/old/v${VERSION}/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mpeg.1:${PORTSDIR}/graphics/mpeg-lib \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

VERSION=	1.1.11
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-perl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gimp.1 gimptool.1
MAN3=		gpc.3
MAN5=		gimprc.5

.include <bsd.port.mk>
