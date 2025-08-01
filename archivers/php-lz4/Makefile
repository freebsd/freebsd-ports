PORTNAME=	lz4
DISTVERSION=	0.5.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pave@FreeBSD.org
COMMENT=	LZ4 extension for PHP
WWW=		https://github.com/kjdev/php-ext-lz4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-lz4

CONFIGURE_ARGS=	--with-lz4-includedir=${LOCALBASE}

.include <bsd.port.mk>
