# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	php-memoize
PORTVERSION=	0.2.0b1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP extension which transparently caches PHP functions

USE_GITHUB=	yes
GH_ACCOUNT=	arraypad

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	memoize
IGNORE_WITH_PHP=	70
CONFIGURE_ARGS=	--enable-memoize

OPTIONS_DEFINE=	APC MEMCACHED MEMORY
OPTIONS_DEFAULT=	MEMORY
APC_DESC=	Enable memoize APC module
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPC}
CONFIGURE_ARGS+=	--enable-memoize-apc
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:www/pecl-APC
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
CONFIGURE_ARGS+=	--with-memoize-memcached
BUILD_DEPENDS+=		libmemcached>0:databases/libmemcached
RUN_DEPENDS+=		libmemcached>0:databases/libmemcached
.endif

.if empty(PORT_OPTIONS:MMEMORY)
CONFIGURE_ARGS+=	--disable-memoize-memory
.endif

.include <bsd.port.post.mk>
