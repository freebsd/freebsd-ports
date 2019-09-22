# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail.com>
# $FreeBSD$

PORTNAME=	ioncube
DISTVERSION=	10.3.1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.ioncube.com/loader_downloads/ \
		http://downloads2.ioncube.com/loader_downloads/ \
		http://dl.ispsystem.info/ioncube/${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}_loaders_fre_${VER}_${ARCH:S,i386,x86,:S,amd64,x86-64,}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	svyatoslav.lempert@gmail.com
COMMENT=	Loader for ionCube-encoded PHP files

LICENSE=	IONCUBE-PHP-LOADER
LICENSE_NAME=	ionCube PHP Loader
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

IGNORE_DragonFly=	is unsupported on DragonFly
ONLY_FOR_ARCHS=	amd64 i386
NO_BUILD=	yes
USES=		php:flavors
IGNORE_WITH_PHP=	74

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

VER=	11

PHP_INSTVER=	${PHP_VERSION:C/^([0-9]+\.[0-9]+).*/\1/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader.so
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}_ts.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader_ts.so
# Put it before opcache, like the previous pkg-message was saying
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "[Zend]" > ${STAGEDIR}${PREFIX}/etc/php/ext-05-ioncube.ini
	@${ECHO_CMD} "zend_extension=${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader.so" >> ${STAGEDIR}${PREFIX}/etc/php/ext-05-ioncube.ini
	@${ECHO_CMD} "zend_extension_ts=${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader_ts.so" >> ${STAGEDIR}${PREFIX}/etc/php/ext-05-ioncube.ini

.include <bsd.port.mk>
