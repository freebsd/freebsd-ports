PORTNAME=	roxygen2
DISTVERSION=	7.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	In-Line Documentation for R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-brew>0:textproc/R-cran-brew \
		R-cran-commonmark>0:textproc/R-cran-commonmark \
		R-cran-desc>=1.2.0:devel/R-cran-desc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-pkgload>=1.0.2:devel/R-cran-pkgload \
		R-cran-purrr>=0.3.3:devel/R-cran-purrr \
		R-cran-R6>=2.1.2:devel/R-cran-R6 \
		R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-stringr>=1.0.0:textproc/R-cran-stringr \
		R-cran-xml2>0:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
