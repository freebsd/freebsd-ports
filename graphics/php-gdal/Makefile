# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.10.1
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	php-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP binding for GDAL

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

ALL_TARGET=	php_gdal.so php_gdalconst.so php_ogr.so php_osr.so
CFLAGS+=	-I${LOCALBASE}/include -fPIC
MAKEFILE=	GNUmakefile
PHP_MOD_NAME=	php_${PORTNAME}
USE_PHP=	yes
USE_PHP_BUILD=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/php

post-patch:
	@${REINPLACE_CMD} -e '/^SWIG = swig/ s|$$|2.0|' ${WRKSRC}/../SWIGmake.base
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
