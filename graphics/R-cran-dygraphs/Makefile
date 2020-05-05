# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dygraphs
DISTVERSION=	1.1.1.6
PORTREVISION=	3
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Interface to Dygraphs Interactive Time Series Charting Library

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-htmlwidgets>=0.6:www/R-cran-htmlwidgets \
		R-cran-htmltools>=0.3.5:textproc/R-cran-htmltools \
		R-cran-zoo>=1.7.10:math/R-cran-zoo \
		R-cran-xts>=0.9.7:math/R-cran-xts
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
