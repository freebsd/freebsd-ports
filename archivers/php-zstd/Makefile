# $FreeBSD$

PORTNAME=	zstd
DISTVERSION=	0.5.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	This is the zstd extension for PHP

LICENSE=	MIT

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		php:ext pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-zstd

CONFIGURE_ARGS=	--with-libzstd

PHP_MODNAME=	zstd

.include <bsd.port.mk>
