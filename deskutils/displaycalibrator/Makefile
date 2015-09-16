# $FreeBSD$

PORTNAME=	displaycalibrator
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/displaycalibrator/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend to xgamma

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/DisplayCalibrator.app/DisplayCalibrator

.include <bsd.port.mk>
