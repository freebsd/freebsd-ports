PORTNAME=	pkgload
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Simulate Package Installation and Attach
WWW=		https://github.com/r-lib/pkgload

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>=3.3.0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=1.0.3:devel/R-cran-rlang \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-withr>=2.4.3:devel/R-cran-withr \
		R-cran-fs>0:sysutils/R-cran-fs
TEST_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-bitops>0:devel/R-cran-bitops \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-pak>0:devel/R-cran-pak \
		R-cran-pkgbuild>0:devel/R-cran-pkgbuild \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.1.0:devel/R-cran-testthat \
		R-cran-mathjaxr>0:math/R-cran-mathjaxr

USES=		cran:auto-plist

.include <bsd.port.mk>
