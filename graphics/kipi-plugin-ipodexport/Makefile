# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libgpod.so:audio/libgpod

KIPI_PLUGIN=	ipodexport
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
