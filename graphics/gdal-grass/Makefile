# New ports collection makefile for:	gdal-grass
# Date created:		Feb 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	gdal-grass
PORTVERSION=	1.3.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.gdal.org/dl/ \
		ftp://ftp.remotesensing.org/gdal/ \
		http://gdal.maptools.org/dl/

MAINTAINER=	lrntct@gmail.org
COMMENT=	GDAL drivers for GRASS raster and vector files

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal
BUILD_DEPENDS=	grass60:${PORTSDIR}/databases/grass
RUN_DEPENDS=	grass60:${PORTSDIR}/databases/grass

GRASS_INST_DIR=	grass
WRKSRC=		${WRKDIR}/${PORTNAME}-1.3.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-grass=${LOCALBASE}/${GRASS_INST_DIR} \
		--with-autoload=${GDAL_AUTOLOAD_DIR}
ALL_TARGET=

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${PREFIX}/share/gdal

.if !defined(GDAL_AUTOLOAD_DIR)
GDAL_AUTOLOAD_DIR=${PREFIX}/lib/gdalplugins
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	grass
.endif

.include <bsd.port.post.mk>
