# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libopencv_legacy.so:graphics/opencv2

KIPI_PLUGIN=	removeredeyes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
