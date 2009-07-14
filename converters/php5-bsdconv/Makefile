# Ports collection makefile for:  php5-bsdconv
# Date created:			  23 May 2009
# Whom:				  buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	2.1
CATEGORIES=	converters
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	php5-
DISTNAME=	buganini-bsdconv-36bc34d41e81babc57f55d490c962c6452f14ccd

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LIB_DEPENDS=	bsdconv.2:${PORTSDIR}/converters/bsdconv

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	bsdconv
CONFIGURE_ARGS+=--with-bsdconv=${LOCALBASE}

WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/php

.include <bsd.port.mk>
