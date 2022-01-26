# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	DiagrammeR
PORTVERSION=	1.0.8
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Create Diagrams and Flowcharts Using R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-dplyr>=1.0.7:math/R-cran-dplyr \
		R-cran-downloader>=0.4:www/R-cran-downloader \
		R-cran-glue>=1.5.0:devel/R-cran-glue \
		R-cran-htmltools>=0.5.2:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>=1.5:www/R-cran-htmlwidgets \
		R-cran-igraph>=1.2.11:math/R-cran-igraph \
		R-cran-influenceR>=0.1.0.1:math/R-cran-influenceR \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-purrr>=0.3.4:devel/R-cran-purrr \
		R-cran-RColorBrewer>=1.1.2:graphics/R-cran-RColorBrewer \
		R-cran-readr>=2.1.1:textproc/R-cran-readr \
		R-cran-rlang>=0.4:devel/R-cran-rlang \
		R-cran-rstudioapi>=0.7:devel/R-cran-rstudioapi \
		R-cran-scales>=1.1:graphics/R-cran-scales \
		R-cran-stringr>=1.4:textproc/R-cran-stringr \
		R-cran-tibble>=3.1:devel/R-cran-tibble \
		R-cran-tidyr>=1.1:devel/R-cran-tidyr \
		R-cran-viridis>=0.6.2:graphics/R-cran-viridis \
		R-cran-visNetwork>=2.1.0:graphics/R-cran-visNetwork
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
