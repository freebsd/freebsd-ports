# New ports collection makefile for:   php5-redis
# Date created:        9 April 2010
# Whom:                Benedikt Niessen <ports@niessen.ch>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	2.1.3
CATEGORIES=	databases
MASTER_SITES=	https://github.com/nicolasff/phpredis/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	nicolasff-phpredis-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	ports@niessen.ch
COMMENT=	PHP5-Extension for Redis

GITVERSION=	43bc590
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/nicolasff-phpredis-${GITVERSION}

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5

PHP_MODNAME=	redis

.include <bsd.port.mk>
