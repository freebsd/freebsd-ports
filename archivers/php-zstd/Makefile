# $FreeBSD$

PORTNAME=	zstd
DISTVERSION=	0.6.1
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	This is the zstd extension for PHP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		php:ext pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-zstd

CONFIGURE_ARGS=	--with-libzstd

.include <bsd.port.mk>
