# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	3.0.0b1
CATEGORIES=	databases
PKGNAMEPREFIX=	php70-

MAINTAINER=	townwear@gmail.com
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached

OPTIONS_DEFINE=	SASL

CONFIGURE_ARGS=	--disable-memcached-sasl --enable-memcached-json --with-libmemcached-dir=${LOCALBASE}
USES=		pkgconfig php:ext
USE_PHP=	session:build json:build
PHP_VER=	70
IGNORE_WITH_PHP=56

USE_GITHUB=	yes
GH_ACCOUNT=	php-memcached-dev
GH_PROJECT=	php-memcached
GH_TAGNAME=	c032fba

PHP_MODNAME=	memcached

SASL_CONFIGURE_ENABLE=	memcached-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
