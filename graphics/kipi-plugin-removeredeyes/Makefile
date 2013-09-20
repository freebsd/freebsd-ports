# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	opencv_legacy:${PORTSDIR}/graphics/opencv

KIPI_PLUGIN=	removeredeyes
NO_STAGE=	yes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
