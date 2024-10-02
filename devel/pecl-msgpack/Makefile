PORTNAME=	msgpack
PORTVERSION=	3.0.0
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Provides API for communicating with MessagePack serialization
WWW=		https://pecl.php.net/package/msgpack

LICENSE=	BSD3CLAUSE

USES=		php:pecl

OPTIONS_DEFINE=		OPCACHE
OPTIONS_DEFAULT=	OPCACHE
OPCACHE_DESC?=		Use OPcache to improve performance

OPCACHE_BUILD_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
OPCACHE_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
OPCACHE_USE=		PHP=opcache

.include <bsd.port.mk>
