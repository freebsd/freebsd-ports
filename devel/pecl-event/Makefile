# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	event
PORTVERSION=	2.5.4
CATEGORIES=	devel

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provides interface to libevent library

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		php:pecl ssl
CONFIGURE_ARGS=	--with-openssl-dir=${OPENSSLBASE}
USE_PHP=	sockets:build
IGNORE_WITH_PHP=	74

.include <bsd.port.mk>
