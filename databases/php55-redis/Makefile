# Created by: Arjan Koole <arjan@blackoak.net>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.2.4
CATEGORIES=	databases
PKGNAMEPREFIX=	php55-

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	nicolasff
GH_PROJECT=	phpredis

USES=		php:ext
USE_PHP=	session:build
PHP_DEFAULT=	5.5
IGNORE_WITH_PHP=	56 70

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIGBINARY}
USE_PHP+=	igbinary:build
CONFIGURE_ARGS+=--enable-redis-igbinary
.else
CONFIGURE_ARGS+=--disable-redis-igbinary
.endif

.include <bsd.port.mk>
