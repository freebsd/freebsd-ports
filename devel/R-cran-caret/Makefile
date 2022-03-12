# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	caret
DISTVERSION=	6.0-91
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Classification and Regression Training

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-e1071>0:science/R-cran-e1071 \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-ModelMetrics>=1.2.2.2:devel/R-cran-ModelMetrics \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-pROC>0:graphics/R-cran-pROC \
		R-cran-recipes>=0.1.10:math/R-cran-recipes \
		R-cran-reshape2>0:devel/R-cran-reshape2 \
		R-cran-withr>=2.0.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
