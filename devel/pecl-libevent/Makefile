# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	libevent
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	webmaster@kibab.com
COMMENT=	Libevent extension for PHP

LICENSE=	PHP301

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	libevent

.include <bsd.port.mk>
