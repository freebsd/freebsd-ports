# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
PORTVERSION=	3.4.4
CATEGORIES=	graphics

MAINTAINER=	mm@FreeBSD.org
COMMENT?=	PHP wrapper to the ImageMagick/GraphicsMagick library version 6

LICENSE=	PHP301

USES=		php:pecl pkgconfig localbase

CONFLICTS_INSTALL?=	${PKGNAMEPREFIX}${PORTNAME}-im7-[0-9]*

OPTIONS_DEFINE=	X11

X11_LIB_DEPENDS?=	libMagickWand-6.so:graphics/ImageMagick6
X11_LIB_DEPENDS_OFF?=	libMagickWand-6.so:graphics/ImageMagick6-nox11

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
