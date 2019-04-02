# $FreeBSD$

PORTNAME=	lz4
DISTVERSION=	0.3.5
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	This is the lz4 extension for PHP

LICENSE=	MIT

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-lz4

CONFIGURE_ARGS=	--with-lz4-includedir=${LOCALBASE}

PHP_MODNAME=	lz4

.include <bsd.port.mk>
