# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gslin@gslin.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

PHP_MODNAME=	memcached
USE_PHP=	json session
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
CONFIGURE_ARGS+=--with-libmemcached-dir=${LOCALBASE} \
		--disable-memcached-sasl

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Binary serializer support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIGBINARY}
CONFIGURE_ARGS+=--enable-memcached-igbinary
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/igbinary.so:${PORTSDIR}/converters/igbinary
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/igbinary.so:${PORTSDIR}/converters/igbinary
.endif

.include <bsd.port.mk>
