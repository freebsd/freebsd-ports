# $FreeBSD$

PORTNAME=	kipi-plugin-${KIPI_PLUGIN}
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

LIB_DEPENDS=	libkvkontakte.so:net/libkvkontakte-kde4

KIPI_PLUGIN=	vkontakte
.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
