# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DiagrammeR
PORTVERSION=	0.8.4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Create Diagrams and Flowcharts Using R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-htmlwidgets>=0.6:www/R-cran-htmlwidgets \
		R-cran-igraph>=1.0.0:math/R-cran-igraph \
		R-cran-influenceR>=0.1.0:math/R-cran-influenceR \
		R-cran-rstudioapi>=0.6:devel/R-cran-rstudioapi \
		R-cran-stringr>=1.0.0:textproc/R-cran-stringr \
		R-cran-visNetwork>=1.0.0:graphics/R-cran-visNetwork \
		R-cran-scales>=0.4.0:graphics/R-cran-scales
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
