PORTNAME=	cairomm
DISTVERSION=	1.14.5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo
WWW=		https://cairographics.org

LICENSE=	LGPL20

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gnome meson pkgconfig tar:xz xorg
USE_GNOME=	cairo libsigc++20
USE_XORG=	x11 xext xrender
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-examples=false \
		-Dbuild-tests=false

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-1.0
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS TEST

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			xsltproc:textproc/libxslt
DOCS_USES=		perl5
DOCS_USE=		perl5=build
DOCS_MESON_TRUE=	build-documentation

TEST_LIB_DEPENDS=	libboost_unit_test_framework.so:devel/boost-libs
TEST_MESON_TRUE=	build-tests

.include <bsd.port.mk>
