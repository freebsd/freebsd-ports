PORTNAME=	plyr
DISTVERSION=	1.8.9
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Tools for splitting, applying, and combining data
WWW=		https://cran.r-project.org/web/packages/plyr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-abind>0:devel/R-cran-abind \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
