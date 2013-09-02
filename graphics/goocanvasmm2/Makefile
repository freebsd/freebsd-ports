# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/goocanvasmm2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvasmm
PORTVERSION=	1.90.9
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	goocanvas-2.0:${PORTSDIR}/graphics/goocanvas2

USES=		pathfix pkgconfig
USE_GNOME=	ltverhack gtkmm30
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_XZ=		yes
USE_GMAKE=	yes

.include <bsd.port.mk>
