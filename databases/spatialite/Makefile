# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialite
PORTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/libspatialite-sources/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Spatial Extensions for SQLite

LICENSE=	MPL11 LGPL20 GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl

GNU_CONFIGURE=	yes
USES=		gmake gnome iconv libtool pathfix pkgconfig sqlite
USE_GNOME=	libxml2

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	--enable-gcp=yes --enable-libxml2=yes \
			CFLAGS="${CFLAGS} -DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1" \
			LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=LWGEOM
LWGEOM_DESC=Enable lwgeom (PostGIS) functions
LWGEOM_CONFIGURE_ENABLE=	lwgeom
LWGEOM_LIB_DEPENDS=	liblwgeom.so:databases/postgis23

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure

.include <bsd.port.mk>
