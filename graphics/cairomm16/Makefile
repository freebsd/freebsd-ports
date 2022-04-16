# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	cairomm
PORTVERSION=	1.16.1
CATEGORIES=	graphics
PKGNAMESUFFIX=	16
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libsigc-3.0.so:devel/libsigc++30

USE_LDCONFIG=	yes
USES=		compiler:c++17-lang gnome libtool meson pathfix pkgconfig \
		tar:xz xorg
USE_CXXSTD=	c++17
USE_GNOME=	cairo libxml++26
USE_XORG=	x11 xext xrender

.include <bsd.port.mk>
