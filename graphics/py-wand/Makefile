PORTNAME=	Wand
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ctypes-based simple MagickWand API binding for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	X11
OPTIONS_SINGLE=	IMAGEMAGICK
OPTIONS_SINGLE_IMAGEMAGICK=	IMAGEMAGICK6 IMAGEMAGICK7
OPTIONS_DEFAULT=IMAGEMAGICK7 X11
IMAGEMAGICK6_DESC=	Use ImageMagick 6.x (graphics/ImageMagick6*)
IMAGEMAGICK7_DESC=	Use ImageMagick 7.x (graphics/ImageMagick7*)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
.if ${PORT_OPTIONS:MIMAGEMAGICK7}
USES=		magick:7
.else
USES=		magick:6
.endif
.else
.if ${PORT_OPTIONS:MIMAGEMAGICK7}
USES=		magick:7,nox11
.else
USES=		magick:6,nox11
.endif
.endif

.include <bsd.port.mk>
