# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

PHP_MODNAME=	memcached
USE_PHP=	json session
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USES=		tar:tgz
CONFIGURE_ARGS+=--with-libmemcached-dir=${LOCALBASE} \
		--disable-memcached-sasl

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Binary serializer support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIGBINARY}
CONFIGURE_ARGS+=--enable-memcached-igbinary
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/igbinary.so:${PORTSDIR}/converters/pecl-igbinary
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/igbinary.so:${PORTSDIR}/converters/pecl-igbinary
.endif

.include <bsd.port.mk>
