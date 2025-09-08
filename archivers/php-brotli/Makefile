PORTNAME=	brotli
DISTVERSION=	0.18.2
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	daniel@shafer.cc
COMMENT=	Brotli extension for PHP
WWW=		https://github.com/kjdev/php-ext-brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

USES=		php:ext pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-brotli
PHP_MODNAME=	${PORTNAME}

CONFIGURE_ARGS=	--with-libbrotli

.include <bsd.port.mk>
