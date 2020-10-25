# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
PORTVERSION=	3.4.4
PORTREVISION=	2
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/Imagick/imagick/commit/
PATCHFILES+=	e1a8d8a99f8eeab13574fcba20c85660a210e350.diff:-p1 \
		ef46023bfba719183a8dcf880c1aa14cf77c006c.diff:-p1 \
		6160bd9617f6c4fc59b7db4ab77460ec085d3169.diff:-p1

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
