PORTNAME=	lintr
DISTVERSION=	3.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	A 'Linter' for R Code
WWW=		https://github.com/r-lib/lintr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-cyclocomp>0:devel/R-cran-cyclocomp \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-backports>=1.1.7:math/R-cran-backports \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-rex>0:textproc/R-cran-rex \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2 \
		R-cran-xmlparsedata>=1.0.5:textproc/R-cran-xmlparsedata
TEST_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rstudioapi>=0.2:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.1.5:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-withr>=2.5.0:devel/R-cran-withr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-httr>=1.2.1:www/R-cran-httr

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
