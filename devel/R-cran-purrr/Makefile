PORTNAME=	purrr
DISTVERSION=	1.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Functional Programming Tools
WWW=		https://cran.r-project.org/package=purrr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.6.1:devel/R-cran-cli \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>=1.5.0:devel/R-cran-magrittr \
		R-cran-rlang>=1.1.1:devel/R-cran-rlang \
		R-cran-vctrs>=0.6.3:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-dplyr>=0.7.8:math/R-cran-dplyr \
		R-cran-httr>0:www/R-cran-httr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-lubridate>0:devel/R-cran-lubridate \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyselect>0:devel/R-cran-tidyselect

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
