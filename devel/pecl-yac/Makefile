# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yac
PORTVERSION=	0.9.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Yac is a shared memory user data cache for PHP

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
USES=		tar:tgz
IGNORE_WITH_PHP=	70

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack

.include <bsd.port.mk>
