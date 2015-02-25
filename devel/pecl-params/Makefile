# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	params
PORTVERSION=	1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL extension for a userspace equivalent of zend_parse_parameters()

USES=		tar:tgz
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-params

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
