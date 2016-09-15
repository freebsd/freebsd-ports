# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	event
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Provides interface to libevent library

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent2

USES=		php:ext tar:tgz
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-openssl-dir=${OPENSSLBASE}
USE_PHP=	sockets:build

.include <bsd.port.mk>
