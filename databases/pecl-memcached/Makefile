PORTNAME=	memcached
PORTVERSION=	3.3.0
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library
WWW=		https://pecl.php.net/package/memcached \
		https://github.com/php-memcached-dev/php-memcached

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmemcached>=1.0.18:databases/libmemcached
LIB_DEPENDS=	libmemcached.so:databases/libmemcached

USES=		php:build,pecl pkgconfig
USE_PHP=	session:build

CONFIGURE_ARGS=	--enable-memcached-json \
		--enable-memcached-protocol \
		--enable-memcached-session \
		--with-libmemcached-dir=${LOCALBASE}

OPTIONS_DEFINE=	IGBINARY MSGPACK SASL
OPTIONS_DEFAULT=SASL
IGBINARY_DESC=	Binary serializer support
MSGPACK_DESC=	MessagePack serializer support

IGBINARY_CONFIGURE_ENABLE=	memcached-igbinary
IGBINARY_USE=		PHP=igbinary:build
MSGPACK_BUILD_DEPENDS=	${PECL_PKGNAMEPREFIX}msgpack>=0:devel/pecl-msgpack@${PHP_FLAVOR}
MSGPACK_CONFIGURE_ENABLE=	memcached-msgpack
MSGPACK_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}msgpack>=0:devel/pecl-msgpack@${PHP_FLAVOR}
SASL_CONFIGURE_ENABLE=	memcached-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2


.include <bsd.port.mk>
