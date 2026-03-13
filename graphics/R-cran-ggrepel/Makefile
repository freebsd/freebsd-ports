PORTNAME=	ggrepel
DISTVERSION=	0.9.7
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Help to avoid overlapping text labels of ggplot2
WWW=		https://cran.r-project.org/package=ggrepel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-ggplot2>=3.5.2:graphics/R-cran-ggplot2 \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rlang>=1.1.6:devel/R-cran-rlang \
		R-cran-scales>=1.4.0:graphics/R-cran-scales \
		R-cran-withr>=3.0.2:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-devtools>0:devel/R-cran-devtools \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-readr>0:textproc/R-cran-readr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-sf>0:math/R-cran-sf \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
