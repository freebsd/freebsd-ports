# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

KIPI_PLUGIN=	dngconverter
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
