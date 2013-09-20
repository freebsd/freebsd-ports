# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	libevent
PORTVERSION=	0.0.5
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	webmaster@kibab.com
COMMENT=	Libevent extension for PHP

LICENSE=	PHP301

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	libevent

NO_STAGE=	yes
.include <bsd.port.mk>
