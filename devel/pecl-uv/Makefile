# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	uv
PORTVERSION=	0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	PHP wrapper for libuv

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

IGNORE_WITH_PHP=	56
USES=		php:ext tar:tgz

.include <bsd.port.mk>
