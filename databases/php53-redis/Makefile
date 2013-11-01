# Created by: Glen Barber <gjb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.2.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/nicolasff/phpredis/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php53-
DISTNAME=	nicolasff-phpredis-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

GITVERSION=	g882c7dc
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/nicolasff-phpredis-250e81b

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53

PHP_MODNAME=	redis

.include <bsd.port.mk>
