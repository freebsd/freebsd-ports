PORTNAME=	PerformanceAnalytics
PORTVERSION=	2.0.8
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Econometric tools for performance and risk analysis
WWW=		https://cran.r-project.org/web/packages/PerformanceAnalytics/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-xts>=0.10.0:math/R-cran-xts \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
