PORTNAME=	pkgload
DISTVERSION=	1.4.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Simulate Package Installation and Attach
WWW=		https://github.com/r-lib/pkgload

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>=3.3.0:devel/R-cran-cli \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-fs>0:filesystems/R-cran-fs \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-pkgbuild>0:devel/R-cran-pkgbuild \
		R-cran-processx>0:sysutils/R-cran-processx \
		R-cran-rlang>=1.1.1:devel/R-cran-rlang \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-withr>=2.4.3:devel/R-cran-withr
TEST_DEPENDS=	R-cran-bitops>0:devel/R-cran-bitops \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-mathjaxr>0:math/R-cran-mathjaxr \
		R-cran-pak>0:devel/R-cran-pak \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.2.1.1:devel/R-cran-testthat \
		R-cran-usethis>0:devel/R-cran-usethis

USES=		cran:auto-plist

.include <bsd.port.mk>
