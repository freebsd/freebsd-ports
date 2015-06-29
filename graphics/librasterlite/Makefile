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

LIB_DEPENDS=	libspatialite.so:${PORTSDIR}/databases/spatialite \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libpng.so:${PORTSDIR}/graphics/png \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreexl.so:${PORTSDIR}/textproc/freexl

GNU_CONFIGURE=	yes
USES=		gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
