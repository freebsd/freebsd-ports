# $FreeBSD$

PORTNAME=		rmagick
PORTVERSION=		2.13.3
CATEGORIES=		graphics rubygems
MASTER_SITES=		RG

MAINTAINER=		ruby@FreeBSD.org
COMMENT=		Ruby binding for ImageMagick

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

USES=		pkgconfig
.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

.include <bsd.port.mk>
