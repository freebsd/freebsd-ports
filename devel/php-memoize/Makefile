# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	memoize
PORTVERSION=	0.2.0b1
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP extension which transparently caches PHP functions

USE_GITHUB=	yes
GH_ACCOUNT=	arraypad
GH_PROJECT=	${UNIQUENAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	cff0a58

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHPBUILD=	yes
CONFIGURE_ARGS=	--enable-memoize

OPTIONS_DEFINE=	APC MEMCACHED MEMORY
OPTIONS_DEFAULT=	MEMORY
APC_DESC=	Enable memoize APC module
MEMCACHED_DESC=	Enable memcached storage module
MEMORY_DESC=	Enable the memoize memory storage module

NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPC}
CONFIGURE_ARGS+=	--enable-memoize-apc
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:${PORTSDIR}/www/pecl-APC
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
CONFIGURE_ARGS+=	--with-memoize-memcached
BUILD_DEPENDS+=		libmemcached>0:${PORTSDIR}/databases/libmemcached
RUN_DEPENDS+=		libmemcached>0:${PORTSDIR}/databases/libmemcached
.endif

.if empty(PORT_OPTIONS:MMEMORY)
CONFIGURE_ARGS+=	--disable-memoize-memory
.endif

.include <bsd.port.post.mk>
