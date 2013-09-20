# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

KIPI_PLUGIN=	dngconverter
NO_STAGE=	yes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
