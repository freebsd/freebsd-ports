PORTNAME=	yac
PORTVERSION=	2.3.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Shared memory user data cache for PHP
WWW=		https://github.com/laruence/yac/wiki

LICENSE=	PHP301

USES=		php:pecl

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
