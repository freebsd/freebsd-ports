# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DiagrammeR
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Create Diagrams and Flowcharts Using R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-dplyr>=0.5.0:math/R-cran-dplyr \
		R-cran-htmlwidgets>=0.8:www/R-cran-htmlwidgets \
		R-cran-igraph>=1.0.1:math/R-cran-igraph \
		R-cran-influenceR>=0.1.0:math/R-cran-influenceR \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-RColorBrewer>=1.1.2:graphics/R-cran-RColorBrewer \
		R-cran-rstudioapi>=0.6:devel/R-cran-rstudioapi \
		R-cran-rgexf>=0.15.3:devel/R-cran-rgexf \
		R-cran-scales>=0.4.1:graphics/R-cran-scales \
		R-cran-stringr>=1.1.0:textproc/R-cran-stringr \
		R-cran-tibble>=1.2:devel/R-cran-tibble \
		R-cran-viridis>=0.3.4:graphics/R-cran-viridis \
		R-cran-visNetwork>=1.0.2:graphics/R-cran-visNetwork
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
