# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	memoize
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP extension which transparently caches PHP functions

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

USES=		php:pecl
CONFIGURE_ARGS=	--enable-memoize
IGNORE_WITH_PHP=	71 72 73

OPTIONS_DEFINE=	MEMCACHED MEMORY
OPTIONS_DEFAULT=MEMORY
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

MEMCACHED_CONFIGURE_ON=	--with-memoize-memcached
MEMCACHED_BUILD_DEPENDS=libmemcached>=0:databases/libmemcached
MEMCACHED_RUN_DEPENDS=	libmemcached>=0:databases/libmemcached
MEMORY_CONFIGURE_OFF=	--disable-memoize-memory

.include <bsd.port.mk>
