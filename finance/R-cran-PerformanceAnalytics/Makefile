# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PerformanceAnalytics
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Econometric tools for performance and risk analysis

LICENSE=	GPLv1

RUN_DEPENDS=	R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-xts>=0.8.9:${PORTSDIR}/math/R-cran-xts

USES=	cran:auto-plist

.include <bsd.port.mk>
