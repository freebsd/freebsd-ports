# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	ev
PORTVERSION=	0.2.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Libev extension for PHP

LICENSE=	PHP301

USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	ev
IGNORE_WITH_PHP=4 52 53

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/php/ext/sockets/php_sockets.h)
USE_PHP=	sockets
CONFIGURE_ARGS+=	--enable-ev-sockets
.else
USE_PHP=	yes
CONFIGURE_ARGS+=	--disable-ev-sockets
.endif

.include <bsd.port.post.mk>
