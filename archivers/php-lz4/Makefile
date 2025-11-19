PORTNAME=	lz4
DISTVERSION=	0.6.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
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

OPTIONS_DEFINE=		APCU
OPTIONS_DEFAULT=	APCU

APCU_DESC=		APCu cache compression support for objects

APCU_BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/apcu/apc_serializer.h:devel/pecl-APCu@${PHP_FLAVOR}

.include <bsd.port.mk>
