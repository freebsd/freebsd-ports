PORTNAME=	dbplyr
DISTVERSION=	2.5.0
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	'dplyr' Back End for Databases
WWW=		https://dbplyr.tidyverse.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-blob>=1.2.0:devel/R-cran-blob \
		R-cran-cli>=3.6.1:devel/R-cran-cli \
		R-cran-DBI>=1.1.3:databases/R-cran-DBI \
		R-cran-dplyr>=1.1.2:math/R-cran-dplyr \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pillar>=1.9.0:devel/R-cran-pillar \
		R-cran-purrr>=1.0.1:devel/R-cran-purrr \
		R-cran-R6>=2.2.2:devel/R-cran-R6 \
		R-cran-rlang>=1.1.1:devel/R-cran-rlang \
		R-cran-tibble>=3.2.1:devel/R-cran-tibble \
		R-cran-tidyr>=1.3.0:devel/R-cran-tidyr \
		R-cran-tidyselect>=1.2.1:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.6.3:devel/R-cran-vctrs \
		R-cran-withr>=2.5.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-RSQLite>=2.3.1:databases/R-cran-RSQLite \
		R-cran-testthat>=3.1.10:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
