PORTNAME=	imagick
PORTVERSION=	3.7.0
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	000.fbsd@quip.cz
COMMENT?=	PHP wrapper to the ImageMagick/GraphicsMagick library
WWW=		https://pecl.php.net/package/imagick

LICENSE=	PHP301

USES=		cpe php:pecl localbase magick

CPE_VENDOR=	php

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
