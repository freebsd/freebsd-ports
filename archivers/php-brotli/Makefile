PORTNAME=	brotli
DISTVERSION=	0.19.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Brotli extension for PHP
WWW=		https://github.com/kjdev/php-ext-brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

USES=		php:ext pkgconfig
IGNORE_WITH_PHP=	86

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-brotli
PHP_MODNAME=	${PORTNAME}

CONFIGURE_ARGS=	--with-libbrotli

OPTIONS_DEFINE=		APCU
OPTIONS_DEFAULT=	APCU

APCU_DESC=		APCu cache compression support for objects

APCU_BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/apcu/apc_serializer.h:devel/pecl-APCu@${PHP_FLAVOR}
APCU_CONFIGURE_ENABLE=	apcu

.include <bsd.port.mk>
