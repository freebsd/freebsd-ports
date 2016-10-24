# Created by: Benedikt Niessen <ports@niessen.ch>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	php56-

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	PHP5 extension for Redis

LICENSE=	PHP301

USES=		php:ext
USE_PHP=	session:build
PHP_VER=	56
IGNORE_WITH_PHP=	70

USE_GITHUB=	yes
GH_ACCOUNT=	nicolasff
GH_PROJECT=	phpredis

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_CONFIGURE_ENABLE=	redis-igbinary
IGBINARY_USE=			php=igbinary:build

.include <bsd.port.mk>
