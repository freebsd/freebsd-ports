PORTNAME=	lintr
DISTVERSION=	3.3.0-1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Linter for R Code
WWW=		https://github.com/r-lib/lintr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-backports>=1.5.0:math/R-cran-backports \
		R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rex>0:textproc/R-cran-rex \
		R-cran-xfun>0:misc/R-cran-xfun \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2 \
		R-cran-xmlparsedata>=1.0.5:textproc/R-cran-xmlparsedata
TEST_DEPENDS=	R-cran-cyclocomp>0:devel/R-cran-cyclocomp \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-patrick>=0.2.0:devel/R-cran-patrick \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>=0.2:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.2.1:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-withr>=2.5.0:devel/R-cran-withr

USES=		cran:auto-plist

MAKE_ENV=	LC_ALL=C.UTF-8

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
