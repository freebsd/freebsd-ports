# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	2012.05.05
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP extension for interfacing with MessagePack

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_TAGNAME=	980a652
WRKSRC_SUBDIR=	php

USES=		php:ext
USE_PHP=	session:build

IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
