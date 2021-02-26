# Created by: Guangyuan Yang <ygy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkgload
DISTVERSION=	1.2.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Simulate Package Installation and Attach

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-pkgbuild>0:devel/R-cran-pkgbuild \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-bitops>0:devel/R-cran-bitops \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
