# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
DISTVERSION=	3.4.1
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Provides a wrapper to the ImageMagick/GraphicsMagick library

LICENSE=	PHP301

OPTIONS_DEFINE=	X11

X11_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:graphics/ImageMagick-nox11

USES=		php:ext pkgconfig tar:tgz localbase

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
