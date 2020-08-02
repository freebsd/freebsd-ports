# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	couchbase
DISTVERSION=	2.6.2
CATEGORIES=	databases

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Couchbase Server PHP extension

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libcouchbase>=2.10.7:databases/libcouchbase
LIB_DEPENDS=	libcouchbase.so:databases/libcouchbase

USES=		php:pecl
USE_PHP=	json:build

.include <bsd.port.mk>
