# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	librasterlite2
PORTVERSION=	1.0.0
DISTVERSIONSUFFIX=-rc0
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite

LICENSE=	MPL GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libspatialite.so:databases/spatialite \
		libsqlite3.so:databases/sqlite3 \
		libgeotiff.so:graphics/libgeotiff \
		libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libfreexl.so:textproc/freexl \
		libwebp.so:graphics/webp \
		libcairo.so:graphics/cairo \
		libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

# Work around PKG_CHECK_MODULES before base r276898
.if !exists(/usr/libdata/pkgconfig/liblzma.pc)
CONFIGURE_ENV+=	LIBLZMA_CFLAGS=" " LIBLZMA_LIBS="-llzma"
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lsqlite3

.include <bsd.port.mk>
