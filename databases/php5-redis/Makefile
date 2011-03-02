# New ports collection makefile for:   php5-redis
# Date created:        9 April 2010
# Whom:                Benedikt Niessen <ports@niessen.ch>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	2.1.0
CATEGORIES=	databases
MASTER_SITES=	https://github.com/owlient/phpredis/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	owlient-phpredis-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	ports@niessen.ch
COMMENT=	PHP5-Extension for Redis

GITVERSION=	8c83275
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/owlient-phpredis-${GITVERSION}

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5

PHP_MODNAME=	redis

.include <bsd.port.mk>
