# Created by: Dan Rowe <bsdports@csnstores.com>
# $FreeBSD$

PORTNAME=	gmagick
PORTVERSION=	1.1.7RC2
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Provides a wrapper to the GraphicsMagick library

LIB_DEPENDS=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-gmagick=${LOCALBASE}

.include <bsd.port.mk>
