PORTNAME=	gdk-pixbuf
PORTVERSION=	2.42.12
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/gdk-pixbuf/-/commit/
PATCHFILES=	4af78023ce7d3b5e3cec422a59bb4f48fa4f5886.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Graphic library for GTK
WWW=		https://developer.gnome.org/gdk-pixbuf/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:build shared-mime-info shebangfix tar:xz trigger
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build libxslt:build
SHEBANG_FILES=	build-aux/*.py
USE_LDCONFIG=	yes
MESON_ARGS=	-Dbuiltin_loaders="none" \
		-Dtests=true \
		-Dinstalled_tests=false
TRIGGERS=	gdk-pixbuf-query-loaders
SUB_LIST=	GTK2_VERSION=${GTK2_VERSION}

LIBVERSION=	0.4200.12
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS GIF JPEG MANPAGES PNG TIFF
OPTIONS_DEFAULT=GIF JPEG MANPAGES PNG TIFF

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

GIF_MESON_ENABLED=	gif

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			rst2man:textproc/py-docutils
MANPAGES_USE=		gnome=libxslt:build
MANPAGES_MESON_TRUE=	man

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

.include <bsd.port.mk>
