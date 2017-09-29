# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
PORTVERSION=	3.4.3
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Provides a wrapper to the ImageMagick/GraphicsMagick library

LICENSE=	PHP301

OPTIONS_DEFINE=	X11

X11_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:graphics/ImageMagick-nox11

USES=		php:pecl pkgconfig localbase

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
