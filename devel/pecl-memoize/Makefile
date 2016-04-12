# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	memoize
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP extension which transparently caches PHP functions

LICENSE=	PHP301

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--enable-memoize
IGNORE_WITH_PHP=	70

OPTIONS_DEFINE=	APC MEMCACHED MEMORY
OPTIONS_DEFAULT=MEMORY
APC_DESC=	Enable memoize APC module
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

APC_CONFIGURE_ON=	--enable-memoize-apc
APC_USE=		PHP=apc
MEMCACHED_CONFIGURE_ON=	--with-memoize-memcached
MEMCACHED_BUILD_DEPENDS=libmemcached>=0:databases/libmemcached
MEMCACHED_RUN_DEPENDS=	libmemcached>=0:databases/libmemcached
MEMORY_CONFIGURE_OFF=	--disable-memoize-memory

.include <bsd.port.mk>
