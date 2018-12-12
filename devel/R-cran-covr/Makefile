# $FreeBSD$

PORTNAME=	covr
DISTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Test Coverage for Packages

LICENSE=	GPLv3

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-withr>=1.0.2:devel/R-cran-withr \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-rex>0:textproc/R-cran-rex \
		R-cran-httr>0:www/R-cran-httr
TEST_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-rstudioapi>=0.2:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-DT>=0.2:textproc/R-cran-DT \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
