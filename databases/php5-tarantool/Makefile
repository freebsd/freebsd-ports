# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	0.1.0
PORTEPOCH=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL PHP driver for Tarantool

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	ignore:1

USES=		php:ext

CONFIGURE_ARGS=	--with-tarantool
IGNORE_WITH_PHP=70 71 72

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-php

.include <bsd.port.mk>
