# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libqjson.so:${PORTSDIR}/devel/qjson

KIPI_PLUGIN=	debianscreenshots
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
