PORTNAME=	spatialite-tools
PORTVERSION=	5.0.1
PORTREVISION=	12
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Collection of CLI tools supporting SpatiaLite
WWW=		http://www.gaia-gis.it/fossil/spatialite-tools/index

LICENSE=	GPLv3

LIB_DEPENDS=	libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl \
		libexpat.so:textproc/expat2 \
		libspatialite.so:databases/spatialite \
		libreadosm.so:astro/readosm

GNU_CONFIGURE=	yes
USES=		gmake gnome iconv minizip pkgconfig sqlite
USE_GNOME=	libxml2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
