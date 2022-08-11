PORTREVISION=	1

PKGNAMESUFFIX=	-im7

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	PHP wrapper to the ImageMagick/GraphicsMagick library version 7

LICENSE=	PHP301

MASTERDIR=	${.CURDIR}/../pecl-imagick

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}${PORTNAME}

X11_USES?=		magick:7
X11_USES_OFF?=		magick:7,nox11

.include "${MASTERDIR}/Makefile"
