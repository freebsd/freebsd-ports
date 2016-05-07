# $FreeBSD$

PORTNAME=	spatialite-tools
PORTVERSION=	4.3.0
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Collection of CLI tools supporting SpatiaLite

LICENSE=	GPLv3

LIB_DEPENDS=	libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl \
		libexpat.so:textproc/expat2 \
		libspatialite.so:databases/spatialite \
		libreadosm.so:astro/readosm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig iconv sqlite

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
