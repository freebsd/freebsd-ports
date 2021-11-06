PORTNAME=	devtools
DISTVERSION=	2.4.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Tools to Make Developing R Packages Easier

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-callr>=3.6.0:devel/R-cran-callr \
		R-cran-cli>=2.4.0:devel/R-cran-cli \
		R-cran-desc>=1.3.0:devel/R-cran-desc \
		R-cran-ellipsis>=0.3.1:devel/R-cran-ellipsis \
		R-cran-fs>=1.5.0:sysutils/R-cran-fs \
		R-cran-httr>=1.4.2:www/R-cran-httr \
		R-cran-lifecycle>=1.0.0:devel/R-cran-lifecycle \
		R-cran-memoise>=1.0.0:devel/R-cran-memoise \
		R-cran-pkgbuild>=1.2.0:devel/R-cran-pkgbuild \
		R-cran-pkgload>=1.2.1:devel/R-cran-pkgload \
		R-cran-rcmdcheck>=1.3.3:devel/R-cran-rcmdcheck \
		R-cran-remotes>=2.3.0:devel/R-cran-remotes \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-roxygen2>=7.1.1:devel/R-cran-roxygen2 \
		R-cran-rstudioapi>=0.13:devel/R-cran-rstudioapi \
		R-cran-rversions>=2.0.2:devel/R-cran-rversions \
		R-cran-sessioninfo>=1.1.1:devel/R-cran-sessioninfo \
		R-cran-testthat>=3.0.2:devel/R-cran-testthat \
		R-cran-usethis>=2.0.0:devel/R-cran-usethis \
		R-cran-withr>=2.4.1:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
