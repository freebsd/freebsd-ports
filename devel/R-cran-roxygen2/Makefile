PORTNAME=	roxygen2
DISTVERSION=	8.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	In-Line Documentation for R
WWW=		https://roxygen2.r-lib.org

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-brew>0:textproc/R-cran-brew \
		R-cran-cli>=3.3.0:devel/R-cran-cli \
		R-cran-commonmark>0:textproc/R-cran-commonmark \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-desc>=1.2.0:devel/R-cran-desc \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-pkgload>=1.5.2:devel/R-cran-pkgload \
		R-cran-R6>=2.1.2:devel/R-cran-R6 \
		R-cran-rdtools>=0.1.0:devel/R-cran-rdtools \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-R.methodsS3>0:devel/R-cran-R.methodsS3 \
		R-cran-R.oo>0:devel/R-cran-R.oo \
		R-cran-rmarkdown>=2.1.6:textproc/R-cran-rmarkdown \
		R-cran-S7>0:devel/R-cran-S7 \
		R-cran-testthat>=3.1.2:devel/R-cran-testthat \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
