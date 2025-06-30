PORTNAME=	librasterlite2
PORTVERSION=	1.1.0
PORTREVISION=	12
DISTVERSIONSUFFIX=-beta1
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/librasterlite2-sources/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite
WWW=		https://www.gaia-gis.it/fossil/librasterlite2/index

LICENSE=	MPL11 GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libspatialite.so:databases/spatialite \
		libgeotiff.so:graphics/libgeotiff \
		libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj \
		libopenjp2.so:graphics/openjpeg \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libcairo.so:graphics/cairo \
		libcurl.so:ftp/curl \
		libfreexl.so:textproc/freexl

GNU_CONFIGURE=	yes
USES=		gmake iconv jpeg libtool pathfix pkgconfig sqlite
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lsqlite3 -lm

.include <bsd.port.mk>
