# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	igbinary
PORTVERSION=	1.2.0
CATEGORIES=	converters
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer

LICENSE=	BSD3CLAUSE

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		tar:tgz

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
