PORTNAME=	collapse
DISTVERSION=	2.1.9
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Advanced and Fast Data Transformation
WWW=		https://cran.r-project.org/package=collapse

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp
TEST_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-kit>0:devel/R-cran-kit \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-microbenchmark>0:devel/R-cran-microbenchmark \
		R-cran-plm>0:finance/R-cran-plm \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

pre-test:
# R-cran-fixest package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("fixest", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
