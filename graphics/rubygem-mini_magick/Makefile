PORTNAME=	mini_magick
PORTVERSION=	4.11.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

OPTIONS_DEFINE=	X11
OPTIONS_SINGLE=	IMAGEMAGICK
OPTIONS_SINGLE_IMAGEMAGICK=	IMAGEMAGICK6 IMAGEMAGICK7
OPTIONS_DEFAULT=IMAGEMAGICK7 X11
IMAGEMAGICK6_DESC=	Use ImageMagick 6.x (graphics/ImageMagick6*)
IMAGEMAGICK7_DESC=	Use ImageMagick 7.x (graphics/ImageMagick7*)

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
.if ${PORT_OPTIONS:MIMAGEMAGICK7}
USES+=		magick:7
.else
USES+=		magick:6
.endif
.else
.if ${PORT_OPTIONS:MIMAGEMAGICK7}
USES+=		magick:7,nox11
.else
USES+=		magick:6,nox11
.endif
.endif

.include <bsd.port.mk>
