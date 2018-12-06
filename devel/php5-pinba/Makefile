# Created by: raven428 <raven428@gmail.com>
# $FreeBSD$

PORTNAME=	pinba
PORTVERSION=	2012.03.20
PORTREVISION=	11
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP-extension part of statistics server for PHP

IGNORE_WITH_PHP=	71 72 73
DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lang php:ext
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	tony2001
GH_PROJECT=	pinba_extension
GH_TAGNAME=	f76b673

.include <bsd.port.mk>
