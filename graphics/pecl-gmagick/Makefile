# Created by: Dan Rowe <bsdports@csnstores.com>
# $FreeBSD$

PORTNAME=	gmagick
PORTVERSION=	1.0.8b1
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	bsdports@csnstores.com
COMMENT=	Provides a wrapper to the GraphicsMagick library

LIB_DEPENDS=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--with-gmagick=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.mk>
