# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gdal-grass
PORTVERSION=	1.4.3
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GDAL drivers for GRASS raster and vector files

LICENSE=	MIT

BUILD_DEPENDS=	grass>=6:${PORTSDIR}/databases/grass
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libgrass_gis.so:${PORTSDIR}/databases/grass
RUN_DEPENDS=	grass>=6:${PORTSDIR}/databases/grass

ALL_TARGET=	# empty
CONFIGURE_ARGS=	--with-autoload=${PREFIX}/lib/gdalplugins \
		--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-grass=${LOCALBASE}/${GRASS_INST_DIR}
GNU_CONFIGURE=	yes
USE_GCC=	yes	# from databases/grass
USES=		gmake

GRASS_INST_DIR!=${MAKE} -C ${.CURDIR}/../../databases/grass/ -V GRASS_INST_DIR

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gdalplugins/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gdal/

.include <bsd.port.mk>
