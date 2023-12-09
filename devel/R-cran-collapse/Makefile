PORTNAME=	collapse
DISTVERSION=	2.0.7
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
		R-cran-kit>0:devel/R-cran-kit \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
