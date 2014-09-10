# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libqca.so:${PORTSDIR}/devel/qca

KIPI_PLUGIN=	shwup
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
