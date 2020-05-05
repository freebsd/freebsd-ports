# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	timeSeries
DISTVERSION=	3042.102
PORTREVISION=	4
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rmetrics - Financial Time Series Objects

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-timeDate>=2150.95:finance/R-cran-timeDate
TEST_DEPENDS=	R-cran-RUnit>0:devel/R-cran-RUnit \
		R-cran-PerformanceAnalytics>0:finance/R-cran-PerformanceAnalytics \
		R-cran-robustbase>0:math/R-cran-robustbase \
		R-cran-xts>0:math/R-cran-xts

USES=		cran:auto-plist

.include <bsd.port.mk>
