# New ports collection makefile for:	imlib
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	imlib
PORTVERSION=	1.9.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/imlib

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib --disable-modules
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-configure:
	${PERL} -pi -e "s^%%LOCALBASE%%^${LOCALBASE}^" ${WRKSRC}/imlib-config.in

.include <bsd.port.mk>
