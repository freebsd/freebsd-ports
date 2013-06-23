# $FreeBSD$

PORTNAME=		rmagick
PORTVERSION=		2.13.2
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

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

.include <bsd.port.mk>
