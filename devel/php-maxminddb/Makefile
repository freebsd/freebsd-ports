# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	MaxMind DB Reader extension for PHP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		compiler:c11 localbase:ldflags php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-php

WRKSRC_SUBDIR=	ext

.include <bsd.port.mk>
