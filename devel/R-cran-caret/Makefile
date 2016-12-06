# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caret
DISTVERSION=	6.0-73
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Classification and Regression Training

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-car>0:math/R-cran-car \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-ModelMetrics>=1.1.0:devel/R-cran-ModelMetrics \
		R-cran-reshape2>0:devel/R-cran-reshape2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
