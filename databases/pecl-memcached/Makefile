# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

USE_PHP=	json session
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USES=		tar:tgz
CONFIGURE_ARGS=	--with-libmemcached-dir=${LOCALBASE} \
		--disable-memcached-sasl

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Binary serializer support

IGBINARY_CONFIGURE_ON=	--enable-memcached-igbinary
IGBINARY_USE=		PHP=igbinary

.include <bsd.port.mk>
