# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	librasterlite
PORTVERSION=	1.1g
PORTREVISION=	5
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/librasterlite-sources/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite

LIB_DEPENDS=	libspatialite.so:${PORTSDIR}/databases/spatialite \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreexl.so:${PORTSDIR}/textproc/freexl

GNU_CONFIGURE=	yes
USES=		gmake iconv pkgconfig libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
