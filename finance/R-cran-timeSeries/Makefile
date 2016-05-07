# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	timeSeries
PORTVERSION=	3022.101.2
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Financial Time Series Objects

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>=2150.95:finance/R-cran-timeDate
TEST_DEPENDS=	R-cran-RUnit>=0:devel/R-cran-RUnit \
		R-cran-xts>=0:math/R-cran-xts \
		R-cran-PerformanceAnalytics>=0:finance/R-cran-PerformanceAnalytics

USES=	cran

.include <bsd.port.mk>
