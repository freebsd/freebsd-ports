# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	4
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libopencv_video.so:graphics/opencv
# Ensure -L${LOCALBASE}/lib is in the linker flags, as 
# the cmake files do not properly handle opencv with tbb
# enabled.
USES+=		localbase:ldflags
CMAKE_ON=	ENABLE_OPENCV3

KIPI_PLUGIN=	removeredeyes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
