PORTNAME=	covr
DISTVERSION=	3.6.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Test Coverage for Packages
WWW=		https://covr.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-httr>0:www/R-cran-httr \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-rex>0:textproc/R-cran-rex \
		R-cran-withr>=1.0.2:devel/R-cran-withr \
		R-cran-yaml>0:textproc/R-cran-yaml
TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-DT>=0.2:textproc/R-cran-DT \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>=0.2:devel/R-cran-rstudioapi \
		R-cran-S7>0:devel/R-cran-S7 \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
