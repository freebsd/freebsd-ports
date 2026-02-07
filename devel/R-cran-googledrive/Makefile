PORTNAME=	googledrive
DISTVERSION=	2.1.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Interface to Google Drive
WWW=		https://googledrive.tidyverse.org/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>=3.0.0:devel/R-cran-cli \
		R-cran-gargle>=1.6.0:devel/R-cran-gargle \
		R-cran-glue>=1.4.2:devel/R-cran-glue \
		R-cran-httr>0:www/R-cran-httr \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pillar>=1.9.0:devel/R-cran-pillar \
		R-cran-purrr>=1.0.1:devel/R-cran-purrr \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-tibble>=2.0.0:devel/R-cran-tibble \
		R-cran-uuid>0:devel/R-cran-uuid \
		R-cran-vctrs>=0.3.0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-dplyr>=1.0.0:math/R-cran-dplyr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=3.1.5:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
