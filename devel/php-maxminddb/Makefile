# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel net
PKGNAMEPREFIX=	php-

MAINTAINER=	danger@FreeBSD.org
COMMENT=	MaxMind DB Reader extension for PHP

LICENSE=	APACHE20

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-php

WRKSRC_SUBDIR=	ext

USES=		php:ext tar:tgz

.include <bsd.port.mk>
