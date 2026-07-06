PORTNAME=	zstd
DISTVERSION=	0.16.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Zstandard extension for PHP
WWW=		https://github.com/kjdev/php-ext-zstd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		php:ext pkgconfig
IGNORE_WITH_PHP=	86

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-zstd

CONFIGURE_ARGS=	--with-libzstd

OPTIONS_DEFINE=		APCU
OPTIONS_DEFAULT=	APCU

APCU_DESC=		APCu cache compression support for objects

APCU_BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/apcu/apc_serializer.h:devel/pecl-APCu@${PHP_FLAVOR}
APCU_CONFIGURE_ENABLE=	apcu

.include <bsd.port.mk>
