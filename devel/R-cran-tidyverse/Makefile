PORTNAME=	tidyverse
DISTVERSION=	2.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Easily Install and Load the 'Tidyverse'
WWW=		https://tidyverse.tidyverse.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-broom>=1.0.3:devel/R-cran-broom \
		R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-conflicted>=1.2.0:devel/R-cran-conflicted \
		R-cran-dbplyr>=2.3.0:databases/R-cran-dbplyr \
		R-cran-dplyr>=1.1.0:math/R-cran-dplyr \
		R-cran-dtplyr>=1.2.2:databases/R-cran-dtplyr \
		R-cran-forcats>=1.0.0:math/R-cran-forcats \
		R-cran-ggplot2>=3.4.1:graphics/R-cran-ggplot2 \
		R-cran-googlesheets4>=1.0.1:devel/R-cran-googlesheets4 \
		R-cran-haven>=2.5.1:math/R-cran-haven \
		R-cran-hms>=1.1.2:devel/R-cran-hms \
		R-cran-httr>=1.4.4:www/R-cran-httr \
		R-cran-jsonlite>=1.8.4:converters/R-cran-jsonlite \
		R-cran-lubridate>=1.9.2:devel/R-cran-lubridate \
		R-cran-magrittr>=2.0.3:devel/R-cran-magrittr \
		R-cran-modelr>=0.1.10:devel/R-cran-modelr \
		R-cran-pillar>=1.8.1:devel/R-cran-pillar \
		R-cran-purrr>=1.0.1:devel/R-cran-purrr \
		R-cran-ragg>=1.2.5:graphics/R-cran-ragg \
		R-cran-readr>=2.1.4:textproc/R-cran-readr \
		R-cran-readxl>=1.4.2:textproc/R-cran-readxl \
		R-cran-reprex>=2.0.2:textproc/R-cran-reprex \
		R-cran-rlang>=1.0.6:devel/R-cran-rlang \
		R-cran-rstudioapi>=0.14:devel/R-cran-rstudioapi \
		R-cran-rvest>=1.0.3:www/R-cran-rvest \
		R-cran-stringr>=1.5.0:textproc/R-cran-stringr \
		R-cran-tibble>=3.1.8:devel/R-cran-tibble \
		R-cran-tidyr>=1.3.0:devel/R-cran-tidyr \
		R-cran-xml2>=1.3.3:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-mockr>0:devel/R-cran-mockr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
