PORTNAME=	tidyr
DISTVERSION=	1.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Easily tidy data with spread and gather functions
WWW=		https://cran.r-project.org/web/packages/tidyr/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.4.1:devel/R-cran-cli \
		R-cran-cpp11>=0.4.0:devel/R-cran-cpp11 \
		R-cran-dplyr>=1.0.10:math/R-cran-dplyr \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-purrr>=1.0.1:devel/R-cran-purrr \
		R-cran-rlang>=1.0.4:devel/R-cran-rlang \
		R-cran-stringr>=1.5.0:textproc/R-cran-stringr \
		R-cran-tibble>=2.1.1:devel/R-cran-tibble \
		R-cran-tidyselect>=1.2.0:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.5.2:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
