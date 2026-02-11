PORTNAME=	cairomm
PORTVERSION=	1.19.0
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
PKGNAMESUFFIX=	11

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo
WWW=		https://cairographics.org

LICENSE=	LGPL21+

TEST_DEPENDS=	boost-libs>0:devel/boost-libs \
		fontconfig>0:x11-fonts/fontconfig

USES=		compiler:c++17-lang gnome meson pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17
USE_GNOME=	cairo libsigc++30 libxslt

MESON_ARGS=	-Dmaintainer-mode=false \
		-Dbuild-documentation=false \
		-Dbuild-examples=false

.include <bsd.port.mk>
