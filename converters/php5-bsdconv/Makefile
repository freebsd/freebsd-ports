# Ports collection makefile for:  php5-bsdconv
# Date created:			  23 May 2009
# Whom:				  buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	4.3
CATEGORIES=	converters
MASTER_SITES=	http://cloud.github.com/downloads/buganini/bsdconv/
PKGNAMEPREFIX=	php5-

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	bsdconv
CONFIGURE_ARGS+=--with-bsdconv=${LOCALBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/wrapper/php

.include <bsd.port.mk>
