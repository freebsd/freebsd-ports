# Created by: Martin Matuska <mm@FreeBSD.org>
PORTREVISION=	1

PKGNAMESUFFIX=	-im7

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	PHP wrapper to the ImageMagick/GraphicsMagick library version 7

LICENSE=	PHP301

MASTERDIR=	${.CURDIR}/../pecl-imagick

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}${PORTNAME}-[0-9]*

X11_LIB_DEPENDS?=	libMagickWand-7.so:graphics/ImageMagick7
X11_LIB_DEPENDS_OFF?=	libMagickWand-7.so:graphics/ImageMagick7-nox11

.include "${MASTERDIR}/Makefile"
