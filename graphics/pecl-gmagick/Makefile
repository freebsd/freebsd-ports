# Created by: Dan Rowe <bsdports@csnstores.com>
# $FreeBSD$

PORTNAME=	gmagick
PORTVERSION=	1.1.7RC3
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Provides a wrapper to the GraphicsMagick library

LICENSE=	PHP301

LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick

USES=		tar:tgz

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-gmagick=${LOCALBASE}

.include <bsd.port.mk>
