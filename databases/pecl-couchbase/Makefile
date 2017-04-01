# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	couchbase
PORTVERSION=	2.3.0
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Couchbase Server PHP extension

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libcouchbase>=2.7.2:databases/libcouchbase
LIB_DEPENDS=	libcouchbase.so:databases/libcouchbase

USE_PHP=	json:build
USES=		php:ext tar:tgz

.include <bsd.port.mk>
