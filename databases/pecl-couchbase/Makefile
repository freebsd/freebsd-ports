# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	couchbase
PORTVERSION=	2.3.2
CATEGORIES=	databases

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Couchbase Server PHP extension

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libcouchbase>=2.7.3:databases/libcouchbase
LIB_DEPENDS=	libcouchbase.so:databases/libcouchbase

USE_PHP=	json:build
USES=		php:pecl

.include <bsd.port.mk>
