PORTNAME=	pkgbuild
DISTVERSION=	1.4.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Find Tools Needed to Build R Packages
WWW=		https://github.com/r-lib/pkgbuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-callr>=3.2.0:devel/R-cran-callr \
		R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-processx>0:sysutils/R-cran-processx \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rprojroot>0:devel/R-cran-rprojroot
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
