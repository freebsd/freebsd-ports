PORTNAME=	later
DISTVERSION=	1.4.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Utilities for Delaying Function Execution
WWW=		https://cran.r-project.org/package=later

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-Rcpp>=0.12.9:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat

USES=		compiler:c++17-lang cran:auto-plist,compiles

.include <bsd.port.mk>
