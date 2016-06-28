# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	3.0.0
CATEGORIES=	databases
PKGNAMEPREFIX=	php70-

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	PHP7 extension for Redis

LICENSE=	PHP301

USES=		php:ext
USE_PHP=	session:build
PHP_DEFAULT=	7.0
IGNORE_WITH_PHP=	55 56

USE_GITHUB=	yes
GH_ACCOUNT=	phpredis
GH_PROJECT=	phpredis

PHP_MODNAME=	redis

.include <bsd.port.mk>
