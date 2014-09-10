# $FreeBSD$

PORTNAME=	libkipiplugins
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${KIPI_PLUGIN}_DESC}

KIPI_PLUGIN=	libkipiplugins
.include "${.CURDIR}/../digikam-kde4/Makefile.common"

USE_KDE4+=	libkdcraw libkexiv2 libkipi
USE_LDCONFIG=	yes

.include <bsd.port.mk>
