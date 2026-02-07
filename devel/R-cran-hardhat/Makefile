PORTNAME=	hardhat
DISTVERSION=	1.4.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Construct Modeling Packages
WWW=		https://cran.r-project.org/package=hardhat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-sparsevctrs>=0.2.0:devel/R-cran-sparsevctrs \
		R-cran-tibble>=3.2.1:devel/R-cran-tibble \
		R-cran-vctrs>=0.6.0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-recipes>0:math/R-cran-recipes \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

pre-test:
# Use absolute path instead of relative
	@${REINPLACE_CMD} -e 's|../man/figures/|${WRKSRC}/man/figures/|g' ${WRKSRC}/vignettes/package.Rmd

# R-cran-modeldata package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("modeldata", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
