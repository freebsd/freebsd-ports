# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dygraphs
PORTVERSION=	0.9
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Interface to Dygraphs Interactive Time Series Charting Library

LICENSE=	MIT

RUN_DEPENDS=	R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-htmlwidgets>=0.3.2:www/R-cran-htmlwidgets \
		R-cran-zoo>=1.7.10:math/R-cran-zoo \
		R-cran-xts>=0.9.7:math/R-cran-xts

USES=	cran:auto-plist

.include <bsd.port.mk>
