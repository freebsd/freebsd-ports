PORTNAME=	tseries
DISTVERSION=	0.10-53
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Time Series Analysis and Computational Finance
WWW=		https://CRAN.R-project.org/package=tseries

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-quantmod>=0.4.9:finance/R-cran-quantmod \
		R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
