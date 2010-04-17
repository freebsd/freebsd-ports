# New ports collection makefile for:   php5-redis
# Date created:        9 April 2010
# Whom:                Benedikt Niessen <ports@niessen.ch>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	1.2.0
CATEGORIES=	databases
MASTER_SITES=	http://ports.niessen.ch/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	php5-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@niessen.ch
COMMENT=	PHP5-Extension for Redis

USE_PHP=	yes
DEFAULT_PHP_VER=5
USE_PHPEXT=	yes

PHP_MODNAME=	redis

.include <bsd.port.mk>
