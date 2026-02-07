PORTNAME=	maxminddb
PORTVERSION=	1.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP Reader for the MaxMind DB Database Format
WWW=		https://github.com/maxmind/MaxMind-DB-Reader-php

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		compiler:c11 localbase:ldflags php:ext

WRKSRC_SUBDIR=	ext

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-php

.include <bsd.port.mk>
