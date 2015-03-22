# Created by: Glen Barber <gjb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.2.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/nicolasff/phpredis/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php53-
DISTNAME=	nicolasff-phpredis-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

GITVERSION=	g882c7dc
WRKSRC=		${WRKDIR}/nicolasff-phpredis-250e81b

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=5 55 56

PHP_MODNAME=	redis

.include <bsd.port.mk>
