# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	${TR_VER}
CATEGORIES=	databases
PKGNAMEPREFIX=	php5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	PECL PHP driver for Tarantool/Box

USE_GITHUB=	yes
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

PHP_MODNAME=	${PORTNAME}
GH_PROJECT=	${PORTNAME}-php
GH_ACCOUNT=	tarantool
GH_TAGNAME=	c1c5d5f
TR_VER=		20151222
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS+=	--with-tarantool

.include <bsd.port.mk>
