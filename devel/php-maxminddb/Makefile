# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	MaxMind DB Reader extension for PHP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-php

WRKSRC_SUBDIR=	ext

USES=		php:ext localbase:ldflags

.include <bsd.port.mk>
