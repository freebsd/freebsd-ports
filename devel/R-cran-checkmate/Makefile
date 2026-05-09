PORTNAME=	checkmate
DISTVERSION=	2.3.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Fast and versatile argument checks
WWW=		https://cran.r-project.org/web/packages/checkmate/

LICENSE=	BSD3CLAUSE

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-data.table>=1.9.8:devel/R-cran-data.table \
		R-cran-devtools>0:devel/R-cran-devtools \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-microbenchmark>0:devel/R-cran-microbenchmark \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.4:devel/R-cran-testthat \
		R-cran-tinytest>=1.1.0:devel/R-cran-tinytest \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
