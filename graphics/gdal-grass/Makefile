PORTNAME=	gdal-grass
PORTVERSION=	2.0.0
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone GRASS Drivers for GDAL and OGR
WWW=		https://github.com/OSGeo/gdal-grass

LICENSE=	MIT

BUILD_DEPENDS=	grass8>=8.4<8.5:databases/grass8
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgrass_gis.so:databases/grass8

USES=		cmake:testing

CFLAGS+=	-fPIC
CMAKE_ARGS=	-DAUTOLOAD_DIR=${PREFIX}/lib/gdalplugins
CMAKE_OFF=	AUTOTEST_DOWNLOAD_TEST_DATA \
		AUTOTEST_SLOW_TEST

PLIST_FILES=	lib/gdalplugins/gdal_GRASS.so \
		lib/gdalplugins/ogr_GRASS.so

USE_GITHUB=	yes
GH_ACCOUNT=	OSGeo

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gdalplugins/*.so

.include <bsd.port.mk>
