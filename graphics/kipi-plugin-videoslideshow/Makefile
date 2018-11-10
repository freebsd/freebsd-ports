# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	6
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick6 \
		libQtGLib-2.0.so:multimedia/gstreamer1-qt@qt4

KIPI_PLUGIN=	videoslideshow
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
