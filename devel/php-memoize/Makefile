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

USES=		php:ext
PHP_MODNAME=	memoize
IGNORE_WITH_PHP=	70
CONFIGURE_ARGS=	--enable-memoize

OPTIONS_DEFINE=	APC MEMCACHED MEMORY
OPTIONS_DEFAULT=	MEMORY
APC_DESC=	Enable memoize APC module
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

APC_CONFIGURE_ENABLE=	memoize-apc
APC_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:www/pecl-APC

MEMCACHED_CONFIGURE_WITH=	memoize-memcached
MEMCACHED_BUILD_DEPENDS=		libmemcached>0:databases/libmemcached
MEMCACHED_RUN_DEPENDS=		libmemcached>0:databases/libmemcached

MEMORY_CONFIGURE_OFF=	--disable-memoize-memory

.include <bsd.port.mk>
