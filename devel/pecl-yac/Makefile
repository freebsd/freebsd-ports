PORTNAME=	yac
PORTVERSION=	2.2.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Shared memory user data cache for PHP

LICENSE=	PHP301

USES=		php:pecl

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}

.include <bsd.port.mk>
