PORTNAME=	usethis
DISTVERSION=	3.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Automate Package and Project Setup
WWW=		https://CRAN.R-project.org/package=usethis

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-cli>=3.0.1:devel/R-cran-cli \
		R-cran-clipr>=0.3.0:devel/R-cran-clipr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-curl>=2.7:ftp/R-cran-curl \
		R-cran-desc>=1.4.2:devel/R-cran-desc \
		R-cran-fs>=1.3.0:sysutils/R-cran-fs \
		R-cran-gert>=1.4.1:devel/R-cran-gert \
		R-cran-gh>=1.2.1:www/R-cran-gh \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>=1.0.0:devel/R-cran-lifecycle \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rappdirs>=0.3.3:devel/R-cran-rappdirs \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-rprojroot>=1.2:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-whisker>0:devel/R-cran-whisker \
		R-cran-withr>=2.3.0:devel/R-cran-withr \
		R-cran-yaml>0:textproc/R-cran-yaml
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-pkgload>=1.3.2.1:devel/R-cran-pkgload \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-roxygen2>=7.1.2:devel/R-cran-roxygen2 \
		R-cran-spelling>=1.2:textproc/R-cran-spelling \
		R-cran-testthat>=3.1.8:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
