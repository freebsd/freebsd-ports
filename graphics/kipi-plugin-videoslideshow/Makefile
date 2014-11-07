# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	4
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libMagickCore-6.Q16.so:${PORTSDIR}/graphics/ImageMagick \
		libQtGStreamer-0.10.so:${PORTSDIR}/multimedia/gstreamer-qt4

KIPI_PLUGIN=	videoslideshow
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
