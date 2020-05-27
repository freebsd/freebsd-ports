# $FreeBSD$

PORTNAME=	lz4
DISTVERSION=	0.3.5
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pave@FreeBSD.org
COMMENT=	LZ4 extension for PHP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-lz4

CONFIGURE_ARGS=	--with-lz4-includedir=${LOCALBASE}

.include <bsd.port.mk>
