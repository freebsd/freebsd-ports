# $FreeBSD$

PORTNAME=	rmagick
PORTVERSION=	2.15.1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick

LICENSE=	MIT

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		pkgconfig

X11_LIB_DEPENDS=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick-nox11

.include <bsd.port.mk>
