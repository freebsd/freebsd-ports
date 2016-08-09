# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	2012.05.05
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP extension for interfacing with MessagePack

DEPRECATED=	This is an older version of the software, please use devel/pecl-msgpack.
EXPIRATION_DATE=	2016-08-31

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_TAGNAME=	980a652
WRKSRC_SUBDIR=	php

USES=		php:ext
USE_PHP=	session:build

IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
