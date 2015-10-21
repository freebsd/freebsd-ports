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
PHP_DEFAULT=	5.4

PHP_MODNAME=	${PORTNAME}
GH_PROJECT=	${PORTNAME}-php
GH_ACCOUNT=	tarantool
GH_TAGNAME=	3f24c5e
TR_VER=		20150708

CONFIGURE_ARGS+=	--with-tarantool

.include <bsd.port.mk>
