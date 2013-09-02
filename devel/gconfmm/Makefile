# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$

PORTNAME=	gconfmm
PORTVERSION=	2.0.2
PORTREVISION=	11
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gconf2 API library

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool
USES=		gmake pkgconfig
USE_GNOME=	gnomehack lthack gconf2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/gconf/gconfmm/client.cc

.include <bsd.port.mk>
