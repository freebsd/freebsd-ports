# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caret
DISTVERSION=	6.0-68
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Classification and Regression Training

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-car>0:math/R-cran-car \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-reshape2>0:devel/R-cran-reshape2

USES=	cran:auto-plist

.include <bsd.port.mk>
