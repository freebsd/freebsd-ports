PORTNAME=	dtplyr
DISTVERSION=	1.3.2
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Data Table Back-End for 'dplyr'
WWW=		https://dtplyr.tidyverse.org/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-data.table>=1.13.0:devel/R-cran-data.table \
		R-cran-dplyr>=1.1.0:math/R-cran-dplyr \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.0.4:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyselect>=1.2.0:devel/R-cran-tidyselect \
		R-cran-vctrs>=0.4.1:devel/R-cran-vctrs
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.1.2:devel/R-cran-testthat \
		R-cran-tidyr>=1.1.0:devel/R-cran-tidyr \
		R-cran-waldo>=0.3.1:devel/R-cran-waldo

USES=		cran:auto-plist

.include <bsd.port.mk>
