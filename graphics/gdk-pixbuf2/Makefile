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

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:3.7+,build shared-mime-info shebangfix tar:xz trigger
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build libxslt:build
SHEBANG_FILES=	build-aux/*.py
USE_LDCONFIG=	yes
MESON_ARGS=	-Dbuiltin_loaders="none" -Dgtk_doc=false -Dinstalled_tests=false
TRIGGERS=	gdk-pixbuf-query-loaders
SUB_LIST=	GTK2_VERSION=${GTK2_VERSION}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JPEG MANPAGES PNG TIFF
OPTIONS_DEFAULT=JPEG MANPAGES PNG TIFF

JPEG_USES=		jpeg
JPEG_MESON_ENABLE=	jpeg

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USE=		gnome=libxslt:build
MANPAGES_MESON_TRUE=	man

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLE=	png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLE=	tiff

.include <bsd.port.mk>
