# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	5
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs
LIB_DEPENDS=	libkgeomap.so:astro/libkgeomap

KIPI_PLUGIN=	gpssync
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
