# $FreeBSD$

PORTNAME=	spatialite-tools
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Collection of CLI tools supporting SpatiaLite

LICENSE=	GPLv3

LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libfreexl.so:${PORTSDIR}/textproc/freexl \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libspatialite.so:${PORTSDIR}/databases/spatialite \
		libreadosm.so:${PORTSDIR}/astro/readosm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_SQLITE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
