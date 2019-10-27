# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tidyr
PORTVERSION=	1.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily tidy data with spread and gather functions

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-dplyr>=0.8.2:math/R-cran-dplyr \
		R-cran-ellipsis>=0.1.0:devel/R-cran-ellipsis \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-tibble>=2.1.1:devel/R-cran-tibble \
		R-cran-tidyselect>=0.2.5:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.2.0:devel/R-cran-vctrs \
		R-cran-lifecycle>0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
