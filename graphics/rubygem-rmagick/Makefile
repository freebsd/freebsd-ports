# $FreeBSD$

PORTNAME=	rmagick
PORTVERSION=	2.16.0
PORTREVISION=	6
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem pkgconfig
USE_RUBY=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:graphics/ImageMagick6-nox11

.include <bsd.port.mk>
