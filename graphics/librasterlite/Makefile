# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	librasterlite
PORTVERSION=	1.1e
PORTREVISION=	2
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/librasterlite-sources/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library that stores and retrieves raster coverages using a SpatiaLite

LIB_DEPENDS=	spatialite:${PORTSDIR}/databases/spatialite \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		geotiff:${PORTSDIR}/graphics/libgeotiff \
		jbig:${PORTSDIR}/graphics/jbigkit \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		tiff:${PORTSDIR}/graphics/tiff \
		freexl:${PORTSDIR}/textproc/freexl

GNU_CONFIGURE=	yes
USES=		pkgconfig iconv
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
		@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
