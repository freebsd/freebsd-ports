# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	${TR_VER}
CATEGORIES=	databases
PKGNAMEPREFIX=	php5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	PECL PHP driver for Tarantool/Box

USES=		php:ext
USE_GITHUB=	yes

GH_PROJECT=	${PORTNAME}-php
GH_TAGNAME=	c1c5d5f
TR_VER=		20151222
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS+=	--with-tarantool

.include <bsd.port.mk>
