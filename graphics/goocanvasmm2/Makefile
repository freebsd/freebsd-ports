# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/goocanvasmm2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvasmm
PORTVERSION=	1.90.9
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	libgoocanvas-2.0.so:graphics/goocanvas2

USES=		compiler:c++11-lang gmake libtool pathfix pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
