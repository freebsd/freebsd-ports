PORTNAME=	gdal-grass
PORTVERSION=	1.0.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone GRASS Drivers for GDAL and OGR
WWW=		https://github.com/OSGeo/gdal-grass

LICENSE=	MIT

BUILD_DEPENDS=	grass8>=8.2<8.3:databases/grass8
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgrass_gis.so:databases/grass8

USES=		gmake

ALL_TARGET=	default
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--with-autoload=${PREFIX}/lib/gdalplugins \
		--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-grass=${LOCALBASE}/grass82
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/gdalplugins/gdal_GRASS.so \
		lib/gdalplugins/ogr_GRASS.so

USE_GITHUB=	yes
GH_ACCOUNT=	OSGeo

.include <bsd.port.mk>
