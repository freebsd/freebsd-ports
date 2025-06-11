PORTNAME=	cairomm
PORTVERSION=	1.18.0
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
PKGNAMESUFFIX=	11

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo
WWW=		https://cairographics.org

LICENSE=	LGPL20+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USE_LDCONFIG=	yes
USES=		compiler:c++17-lang gnome meson pkgconfig tar:xz
USE_CXXSTD=	c++17
USE_GNOME=	cairo libsigc++30 libxslt

MESON_ARGS=	-Dmaintainer-mode=false \
		-Dbuild-documentation=false \
		-Dbuild-examples=false \
		-Dbuild-tests=false

.include <bsd.port.mk>
