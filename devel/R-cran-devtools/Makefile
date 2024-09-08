PORTNAME=	devtools
DISTVERSION=	2.4.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Tools to Make Developing R Packages Easier
WWW=		https://CRAN.R-project.org/package=devtools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.3.0:devel/R-cran-cli \
		R-cran-desc>=1.4.1:devel/R-cran-desc \
		R-cran-ellipsis>=0.3.2:devel/R-cran-ellipsis \
		R-cran-fs>=1.5.2:sysutils/R-cran-fs \
		R-cran-httr>=1.4.2:www/R-cran-httr \
		R-cran-lifecycle>=1.0.1:devel/R-cran-lifecycle \
		R-cran-memoise>=2.0.1:devel/R-cran-memoise \
		R-cran-miniUI>=0.1.1.1:www/R-cran-miniUI \
		R-cran-pkgbuild>=1.3.1:devel/R-cran-pkgbuild \
		R-cran-pkgdown>=2.0.6:www/R-cran-pkgdown \
		R-cran-pkgload>=1.3.0:devel/R-cran-pkgload \
		R-cran-profvis>=0.3.7:devel/R-cran-profvis \
		R-cran-rcmdcheck>=1.4.0:devel/R-cran-rcmdcheck \
		R-cran-remotes>=2.4.2:devel/R-cran-remotes \
		R-cran-rlang>=1.0.4:devel/R-cran-rlang \
		R-cran-roxygen2>=7.2.1:devel/R-cran-roxygen2 \
		R-cran-rversions>=2.1.1:devel/R-cran-rversions \
		R-cran-sessioninfo>=1.2.2:devel/R-cran-sessioninfo \
		R-cran-testthat>=3.1.5:devel/R-cran-testthat \
		R-cran-urlchecker>=1.0.1:devel/R-cran-urlchecker \
		R-cran-usethis>=2.1.6:devel/R-cran-usethis \
		R-cran-withr>=2.5.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
