PORTNAME=	spatialite-tools
PORTVERSION=	5.0.1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Collection of CLI tools supporting SpatiaLite

LICENSE=	GPLv3

LIB_DEPENDS=	libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl \
		libexpat.so:textproc/expat2 \
		libspatialite.so:databases/spatialite \
		libreadosm.so:astro/readosm \
		libminizip.so:archivers/minizip

GNU_CONFIGURE=	yes
USES=		gmake gnome pkgconfig iconv sqlite
USE_GNOME=	libxml2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
