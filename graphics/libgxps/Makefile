# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libgxps
PORTVERSION=	0.2.3.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for rendering XPS documents

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		liblcms2.so:graphics/lcms2

USES=		gettext gmake jpeg libtool libarchive pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomeprefix glib20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-introspection \
		--disable-compile-warnings
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
