# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DiagrammeR
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Create Diagrams and Flowcharts Using R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-dplyr>=0.7.6:math/R-cran-dplyr \
		R-cran-downloader>=0.4:www/R-cran-downloader \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-htmltools>=0.3.6:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>=1.2:www/R-cran-htmlwidgets \
		R-cran-igraph>=1.1.2:math/R-cran-igraph \
		R-cran-influenceR>=0.1.0:math/R-cran-influenceR \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-purrr>=0.2.5:devel/R-cran-purrr \
		R-cran-RColorBrewer>=1.1.2:graphics/R-cran-RColorBrewer \
		R-cran-readr>=1.1.1:textproc/R-cran-readr \
		R-cran-rlang>=0.2.2:devel/R-cran-rlang \
		R-cran-rstudioapi>=0.7:devel/R-cran-rstudioapi \
		R-cran-scales>=1.0.0:graphics/R-cran-scales \
		R-cran-stringr>=1.3.0:textproc/R-cran-stringr \
		R-cran-tibble>=1.4.2:devel/R-cran-tibble \
		R-cran-tidyr>=0.8.1:devel/R-cran-tidyr \
		R-cran-viridis>=0.5.1:graphics/R-cran-viridis \
		R-cran-visNetwork>=2.0.4:graphics/R-cran-visNetwork
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
