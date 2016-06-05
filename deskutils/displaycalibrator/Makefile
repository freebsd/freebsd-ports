# $FreeBSD$

PORTNAME=	displaycalibrator
PORTVERSION=	0.7
PORTREVISION=	6
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/displaycalibrator/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend to xgamma

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/DisplayCalibrator.app/DisplayCalibrator

.include <bsd.port.mk>
