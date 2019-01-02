# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	3.1.3
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmemcached>=1.0.18:databases/libmemcached
LIB_DEPENDS=	libmemcached.so:databases/libmemcached

OPTIONS_DEFINE=	IGBINARY SASL
OPTIONS_DEFAULT=SASL
IGBINARY_DESC=	Binary serializer support

USES=		php:pecl pkgconfig
USE_PHP=	json:build session:build

CONFIGURE_ARGS=	--with-libmemcached-dir=${LOCALBASE}

IGBINARY_CONFIGURE_ENABLE=	memcached-igbinary
IGBINARY_USE=		PHP=igbinary:build
SASL_CONFIGURE_ENABLE=	memcached-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
