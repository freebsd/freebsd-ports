PORTNAME=	devtools
DISTVERSION=	2.5.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Tools to Make Developing R Packages Easier
WWW=		https://cran.r-project.org/package=devtools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>=3.6.6:devel/R-cran-cli \
		R-cran-desc>=1.4.3:devel/R-cran-desc \
		R-cran-ellipsis>=0.3.3:devel/R-cran-ellipsis \
		R-cran-fs>=2.1.0:filesystems/R-cran-fs \
		R-cran-lifecycle>=1.0.5:devel/R-cran-lifecycle \
		R-cran-memoise>=2.0.1:devel/R-cran-memoise \
		R-cran-miniUI>=0.1.2:www/R-cran-miniUI \
		R-cran-pkgbuild>=1.4.8:devel/R-cran-pkgbuild \
		R-cran-pkgdown>=2.2.0:www/R-cran-pkgdown \
		R-cran-pkgload>=1.5.2:devel/R-cran-pkgload \
		R-cran-profvis>=0.4.0:devel/R-cran-profvis \
		R-cran-rcmdcheck>=1.4.0:devel/R-cran-rcmdcheck \
		R-cran-remotes>=2.5.0:devel/R-cran-remotes \
		R-cran-rlang>=1.2.0:devel/R-cran-rlang \
		R-cran-roxygen2>=7.3.3:devel/R-cran-roxygen2 \
		R-cran-rversions>=3.0.0:devel/R-cran-rversions \
		R-cran-sessioninfo>=1.2.3:devel/R-cran-sessioninfo \
		R-cran-testthat>=3.3.2:devel/R-cran-testthat \
		R-cran-urlchecker>=1.0.1:devel/R-cran-urlchecker \
		R-cran-usethis>=3.2.1:devel/R-cran-usethis \
		R-cran-withr>=3.0.2:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
