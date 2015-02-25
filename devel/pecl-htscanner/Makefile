# Created by: chinsan
# $FreeBSD$

PORTNAME=	htscanner
PORTVERSION=	1.0.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support htaccess for PHP

LICENSE=	PHP30

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-htscanner

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
