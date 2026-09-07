PORTNAME=	styler
DISTVERSION=	1.11.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Non-Invasive Pretty Printing of R Code
WWW=		https://cran.r-project.org/package=styler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>=3.1.1:devel/R-cran-cli \
		R-cran-magrittr>=2.0.0:devel/R-cran-magrittr \
		R-cran-purrr>=1.0.2:devel/R-cran-purrr \
		R-cran-R.cache>=0.15.0:devel/R-cran-R.cache \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-rprojroot>=1.1:devel/R-cran-rprojroot \
		R-cran-vctrs>=0.4.1:devel/R-cran-vctrs \
		R-cran-withr>=2.3.0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-prettycode>0:devel/R-cran-prettycode \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-roxygen2>0:devel/R-cran-roxygen2 \
		R-cran-rstudioapi>=0.7:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.2.1:devel/R-cran-testthat \
		R-cran-tibble>=1.4.2:devel/R-cran-tibble

USES=		cran:auto-plist shebangfix

SHEBANG_FILES=		tests/dev/generate_roxygen_tests.R
SHEBANG_LANG=		Rscript
Rscript_OLD_CMD=	/usr/bin/Rscript
Rscript_CMD=		${LOCALBASE}/bin/Rscript

TESTING_UNSAFE=	yes

.include <bsd.port.mk>
