PORTNAME=	googledrive
DISTVERSION=	2.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Interface to Google Drive
WWW=		https://googledrive.tidyverse.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.0.0:devel/R-cran-cli \
		R-cran-gargle>=1.5.0:devel/R-cran-gargle \
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
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-mockr>0:devel/R-cran-mockr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
