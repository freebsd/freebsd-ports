# New ports collection makefile for:   php5-redis
# Date created:        9 April 2010
# Whom:                Benedikt Niessen <ports@niessen.ch>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/nicolasff/phpredis/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	nicolasff-phpredis-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

GITVERSION=	g882c7dc
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/nicolasff-phpredis-250e81b

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5

PHP_MODNAME=	redis

.include <bsd.port.mk>
