PORTNAME=	openslide
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1-293
DISTVERSIONSUFFIX=	-gdd3a152
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading virtual slide images
WWW=		https://openslide.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		autoreconf gettext-runtime gmake gnome jpeg libtool pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 glib20 libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
