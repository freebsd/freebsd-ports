# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialite
PORTVERSION=	4.3.0
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Spatial Extensions for SQLite

BROKEN=		unfetchable

LICENSE=	MPL LGPL20 GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libfreexl.so:${PORTSDIR}/textproc/freexl

WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig libtool
USE_SQLITE=	yes
USE_GNOME=	libxml2

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+= --enable-gcp=yes --enable-libxml2=yes CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=LWGEOM
LWGEOM_DESC=Enable lwgeom (PostGIS) functions
LWGEOM_CONFIGURE_ENABLE=	lwgeom
LWGEOM_LIB_DEPENDS=	liblwgeom.so:${PORTSDIR}/databases/postgis21

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure

.include <bsd.port.mk>
