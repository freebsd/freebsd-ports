# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	librasterlite
PORTVERSION=	1.1g
PORTREVISION=	10
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/librasterlite-sources/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite

LICENSE=	MPL GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libspatialite.so:databases/spatialite \
		libsqlite3.so:databases/sqlite3 \
		libgeotiff.so:graphics/libgeotiff \
		libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libfreexl.so:textproc/freexl

GNU_CONFIGURE=	yes
USES=		gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lsqlite3 -lm

.include <bsd.port.mk>
