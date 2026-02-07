PORTNAME=	modelr
DISTVERSION=	0.1.11
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Modelling Functions that Work with the Pipe
WWW=		https://modelr.tidyverse.org

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-broom>0:devel/R-cran-broom \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-purrr>=0.2.2:devel/R-cran-purrr \
		R-cran-rlang>=1.0.6:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyr>=0.8.0:devel/R-cran-tidyr \
		R-cran-tidyselect>0:devel/R-cran-tidyselect \
		R-cran-vctrs>0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
