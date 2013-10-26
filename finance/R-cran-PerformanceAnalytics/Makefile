# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PerformanceAnalytics
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Econometric tools for performance and risk analysis

LICENSE=	GPLv1

RUN_DEPENDS=	R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-xts>=0.8.9:${PORTSDIR}/math/R-cran-xts

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
