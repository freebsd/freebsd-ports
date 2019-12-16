# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.40.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:3.4+,build shared-mime-info tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build libxslt:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dman=true

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JASPER JPEG PNG TIFF X11
OPTIONS_DEFAULT=JPEG PNG TIFF X11

JASPER_MESON_TRUE=	jasper
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper

JPEG_MESON_TRUE=	jpeg
JPEG_USES=		jpeg

PNG_MESON_TRUE=		png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

TIFF_MESON_TRUE=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

X11_MESON_TRUE=		x11
X11_USES=		xorg
X11_USE=		xorg=x11

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/libexec/installed-tests
	${RM} -rf ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
