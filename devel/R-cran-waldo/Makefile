PORTNAME=	waldo
DISTVERSION=	0.4.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Find Differences Between R Objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-diffobj>=0.3.4:devel/R-cran-diffobj \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rematch2>0:devel/R-cran-rematch2 \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble
TEST_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
