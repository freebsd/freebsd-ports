# New ports collection makefile for:	imlib
# Version required:	1.9.8
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	imlib-1.9.8
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/enlightenment/enlightenment/libs/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gif.5:${PORTSDIR}/graphics/giflib \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
