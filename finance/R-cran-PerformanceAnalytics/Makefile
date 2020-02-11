# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PerformanceAnalytics
PORTVERSION=	2.0.4
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Econometric tools for performance and risk analysis

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-xts>=0.10.0:math/R-cran-xts \
		R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-zoo>0:math/R-cran-zoo
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
