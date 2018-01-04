# Created by: Dan Rowe <bsdports@csnstores.com>
# $FreeBSD$

PORTNAME=	gmagick
PORTVERSION=	1.1.7RC3
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Provides a wrapper to the GraphicsMagick library

LICENSE=	PHP301

LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick

USES=		php:pecl

IGNORE_WITH_PHP=	70 71 72

CONFIGURE_ARGS=	--with-gmagick=${LOCALBASE}

.include <bsd.port.mk>
