PORTNAME=	gdk-pixbuf
PORTVERSION=	2.42.8
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:3.7+,build shared-mime-info tar:xz trigger
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build libxslt:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dman=true -Dbuiltin_loaders="none" -Dinstalled_tests=false
TRIGGERS=	gdk-pixbuf-query-loaders
SUB_LIST=	GTK2_VERSION=${GTK2_VERSION}

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JPEG PNG TIFF
OPTIONS_DEFAULT=JPEG PNG TIFF

JPEG_MESON_ENABLE=	jpeg
JPEG_USES=		jpeg

PNG_MESON_ENABLE=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

TIFF_MESON_ENABLE=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

.include <bsd.port.mk>
