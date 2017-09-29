# $FreeBSD$

PORTNAME=	rmagick
PORTVERSION=	2.16.0
PORTREVISION=	5
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick

LICENSE=	MIT

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

USE_RUBY=	yes
USES=		gem pkgconfig

X11_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:graphics/ImageMagick-nox11

.include <bsd.port.mk>
