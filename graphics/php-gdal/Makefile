# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	2.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/gdal/${PORTVERSION}/ \
		ftp://ftp.remotesensing.org/pub/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	php-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libgdal.so:graphics/gdal

ALL_TARGET=	php_gdal.so php_gdalconst.so php_ogr.so php_osr.so
CFLAGS+=	-fPIC
IGNORE_WITH_PHP=70
MAKEFILE=	GNUmakefile
PHP_MOD_NAME=	php_${PORTNAME}
USES=		php:build gmake localbase tar:xz

WRKSRC_SUBDIR=	swig/php

post-patch:
	@${REINPLACE_CMD} -e '/^SWIG = swig/ s|$$|3.0|' ${WRKSRC}/../SWIGmake.base
	@${REINPLACE_CMD} -e 's|^CC=.*$$|CC=${CC}|; s|^CXX=.*$$|CXX=${CXX}|; s|^CFLAGS=.*$$|CFLAGS=${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

# include/cpl_config.h will exist after build phase
pre-build:
	${SED} -e '/^GDAL_ROOT/d' ${DATADIR}/GDALmake.opt > ${WRKSRC}/../../GDALmake.opt
	${CP} ${LOCALBASE}/include/cpl_config.h ${WRKSRC}/../../port/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ ${STAGEDIR}${PREFIX}/include/php/ext/${PORTNAME}/
	${INSTALL_LIB} ${WRKSRC}/*.so ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/php/ext/${PORTNAME}/

.include <bsd.port.mk>
