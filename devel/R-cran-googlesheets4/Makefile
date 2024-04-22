PORTNAME=	googlesheets4
DISTVERSION=	1.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Access Google Sheets using the Sheets API V4
WWW=		https://googlesheets4.tidyverse.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cellranger>0:textproc/R-cran-cellranger \
		R-cran-cli>=3.0.0:devel/R-cran-cli \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-gargle>=1.5.0:devel/R-cran-gargle \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-googledrive>=2.1.0:devel/R-cran-googledrive \
		R-cran-httr>0:www/R-cran-httr \
		R-cran-ids>0:devel/R-cran-ids \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rematch2>0:devel/R-cran-rematch2 \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-tibble>=2.1.1:devel/R-cran-tibble \
		R-cran-vctrs>=0.2.3:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
