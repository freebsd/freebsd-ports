# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	2012.05.05
CATEGORIES=	devel
MASTER_SITES=	http://github.com/${GITHUB_USER}/${GITHUB_REPO}/tarball/${GITVERSION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	msgpack-msgpack-${GITVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP extension for interfacing with MessagePack

WRKSRC=		${WRKDIR}/msgpack-msgpack-${GITVERSION}/php

GITHUB_USER=	msgpack
GITHUB_REPO=	msgpack
GITVERSION=	980a652

USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	msgpack

NO_STAGE=	yes
.include <bsd.port.mk>
