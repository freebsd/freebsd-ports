PORTNAME=	openslide
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading virtual slide images
WWW=		https://openslide.org \
		https://github.com/openslide/openslide

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libdicom.so:graphics/libdicom \
		libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd

USES=		gettext-runtime gnome jpeg meson pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	cairo glib20 libxml2
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddoc=disabled \
		-Dtest=disabled

.include <bsd.port.mk>
