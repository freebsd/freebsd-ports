# $FreeBSD$

PORTNAME=	libkipiplugins
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	2
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

KIPI_PLUGIN=	libkipiplugins
.include "${.CURDIR}/../digikam-kde4/Makefile.common"

USE_KDE+=	libkdcraw libkexiv2 libkipi
USE_LDCONFIG=	yes

.include <bsd.port.mk>
