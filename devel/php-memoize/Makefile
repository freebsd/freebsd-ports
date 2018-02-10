# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	php-memoize
PORTVERSION=	0.2.0b1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP extension which transparently caches PHP functions

USE_GITHUB=	yes
GH_ACCOUNT=	arraypad

USES=		php:ext
PHP_MODNAME=	memoize
IGNORE_WITH_PHP=	70 71 72
CONFIGURE_ARGS=	--enable-memoize

OPTIONS_DEFINE=	MEMCACHED MEMORY
OPTIONS_DEFAULT=	MEMORY
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

MEMCACHED_CONFIGURE_WITH=	memoize-memcached
MEMCACHED_BUILD_DEPENDS=		libmemcached>0:databases/libmemcached
MEMCACHED_RUN_DEPENDS=		libmemcached>0:databases/libmemcached

MEMORY_CONFIGURE_OFF=	--disable-memoize-memory

.include <bsd.port.mk>
