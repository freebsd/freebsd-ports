# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	operator
PORTVERSION=	0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension that provides operator overloading for PHP objects

LICENSE=	PHP30

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_VERSIONS+=	php=53
PHP_MODNAME=	${PORTNAME}

post-extract::
	@${CAT} ${PKGMESSAGE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
