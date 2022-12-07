PORTNAME=	fGarch
DISTVERSION=	4022.89
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Rmetrics - Autoregressive Conditional Heteroskedastic Modelling
WWW=		https://www.rmetrics.org

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-fBasics>0:finance/R-cran-fBasics \
		R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-timeSeries>0:finance/R-cran-timeSeries \
		R-cran-cvar>=0.5:math/R-cran-cvar \
		R-cran-fastICA>0:science/R-cran-fastICA
TEST_DEPENDS=	R-cran-RUnit>0:devel/R-cran-RUnit

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
