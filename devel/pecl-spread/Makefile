# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spread
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Php Interface to the Spread Toolkit API

LICENSE=	PHP301

BUILD_DEPENDS=	${LOCALBASE}/include/sp.h:${PORTSDIR}/net/spread4
RUN_DEPENDS=	${LOCALBASE}/include/sp.h:${PORTSDIR}/net/spread4

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53

CONFIGURE_ARGS+=--with-spread=${LOCALBASE}

.include <bsd.port.mk>
