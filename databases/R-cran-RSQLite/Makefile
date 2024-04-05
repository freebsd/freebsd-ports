PORTNAME=	RSQLite
PORTVERSION=	2.3.6
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Database Interface R driver for SQLite
WWW=		https://cran.r-project.org/web/packages/RSQLite/

LICENSE=	LGPL21

CRAN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-blob>=1.2.0:devel/R-cran-blob \
		R-cran-cpp11>=0.4.0:devel/R-cran-cpp11 \
		R-cran-DBI>=1.2.0:databases/R-cran-DBI \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-plogr>=0.2.0:devel/R-cran-plogr \
		R-cran-Rcpp>=0.4.00:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
