# New ports collection makefile for:	imlib
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	imlib
PORTVERSION=	1.9.14
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/imlib/1.9
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic library for enlightenment package

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib --disable-modules \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		imlib-config.1 imlib_config.1

pre-configure:
	${REINPLACE_CMD} -e "s^%%LOCALBASE%%^${LOCALBASE}^" ${WRKSRC}/imlib-config.in

.include <bsd.port.mk>
