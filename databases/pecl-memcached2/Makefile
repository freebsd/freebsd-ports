# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	databases
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached

OPTIONS_DEFINE=	IGBINARY SASL
OPTIONS_DEFAULT=SASL
IGBINARY_DESC=	Binary serializer support

PORTSCOUT=	limit:^2\.

CONFIGURE_ARGS=	--with-libmemcached-dir=${LOCALBASE}
IGNORE_WITH_PHP=70 71
USE_PHP=	json:build session:build
USES=		php:pecl pkgconfig

IGBINARY_CONFIGURE_ENABLE=	memcached-igbinary
IGBINARY_USE=		PHP=igbinary:build
SASL_CONFIGURE_ENABLE=	memcached-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
