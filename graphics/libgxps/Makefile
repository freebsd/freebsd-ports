# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libgxps
PORTVERSION=	0.3.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for rendering XPS documents

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		liblcms2.so:graphics/lcms2

USES=		gettext gnome jpeg libarchive localbase meson pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo glib20 introspection:build

MESON_ARGS=	-Denable-test=false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
