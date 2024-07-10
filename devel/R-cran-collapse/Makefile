PORTNAME=	collapse
DISTVERSION=	2.0.15
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Advanced and Fast Data Transformation
WWW=		https://cran.r-project.org/web/packages/collapse/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-kit>0:devel/R-cran-kit \
		R-cran-microbenchmark>0:devel/R-cran-microbenchmark \
		R-cran-plm>0:finance/R-cran-plm \
		R-cran-testthat>0:devel/R-cran-testthat
# Tests: 'fixest' required (?) not ported yet

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
