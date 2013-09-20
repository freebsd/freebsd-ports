# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	kgeomap:${PORTSDIR}/astro/libkgeomap

KIPI_PLUGIN=	gpssync
NO_STAGE=	yes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
