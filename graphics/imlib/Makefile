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

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib \
		--disable-gtktest

pre-configure:
	${PERL} -pi -e "s^%%LOCALBASE%%^${LOCALBASE}^" ${WRKSRC}/imlib-config.in

.include <bsd.port.mk>
