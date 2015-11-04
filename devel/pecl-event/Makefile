# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	event
PORTVERSION=	1.11.1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Provides interface to libevent library

LICENSE=	PHP301

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USES=		tar:tgz
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-openssl-dir=${OPENSSLBASE}
USE_PHP=	sockets
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	event
IGNORE_WITH_PHP=52 53

.include <bsd.port.mk>
