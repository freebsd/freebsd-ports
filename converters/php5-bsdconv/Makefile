# Ports collection makefile for:  php5-bsdconv
# Date created:			  23 May 2009
# Whom:				  buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	1.11
CATEGORIES=	converters
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	php5-
DISTNAME=	buganini-bsdconv-583422ced076a6b034160dea835d8e4b2a9d7371

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LIB_DEPENDS=	bsdconv.1:${PORTSDIR}/converters/bsdconv

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	bsdconv
CONFIGURE_ARGS+=LDARGS="-L${LOCALBASE}/lib -lbsdconv"

WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/php

.include <bsd.port.mk>
