# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gdal-grass
PORTVERSION=	1.11.2
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GDAL drivers for GRASS raster and vector files

LICENSE=	MIT

BUILD_DEPENDS=	grass>=6:${PORTSDIR}/databases/grass
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libgrass_gis.so:${PORTSDIR}/databases/grass
RUN_DEPENDS=	grass>=6:${PORTSDIR}/databases/grass

USES=		gmake
USE_GCC=	yes	# from databases/grass
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-autoload=${PREFIX}/lib/gdalplugins \
		--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-grass=${LOCALBASE}/${GRASS_INST_DIR}
ALL_TARGET=	default

GRASS_INST_DIR!=${MAKE} -C ${.CURDIR}/../../databases/grass/ -V GRASS_INST_DIR

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gdalplugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gdal

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gdalplugins/*_GRASS.so

.include <bsd.port.mk>
