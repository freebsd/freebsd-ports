# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	librasterlite2
PORTVERSION=	1.0.0
DISTVERSIONSUFFIX=-rc0
PORTREVISION=	2
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite

LICENSE=	MPL GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libspatialite.so:${PORTSDIR}/databases/spatialite \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libpng.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreexl.so:${PORTSDIR}/textproc/freexl \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libcurl.so:${PORTSDIR}/ftp/curl

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
