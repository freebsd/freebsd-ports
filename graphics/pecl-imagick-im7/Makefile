# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-im7

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PHP wrapper to the ImageMagick/GraphicsMagick library version 7

LICENSE=	PHP301

MASTERDIR=	${.CURDIR}/../pecl-imagick

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}${PORTNAME}-[0-9]*

X11_LIB_DEPENDS?=	libMagickWand-7.so:graphics/ImageMagick7
X11_LIB_DEPENDS_OFF?=	libMagickWand-7.so:graphics/ImageMagick7-nox11

.include "${MASTERDIR}/Makefile"
