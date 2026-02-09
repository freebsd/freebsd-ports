PORTNAME=	vctrs
DISTVERSION=	0.7.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Vector Helpers
WWW=		https://cran.r-project.org/package=vctrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-rlang>=1.1.7:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>=0.8.5:devel/R-cran-crayon \
		R-cran-dplyr>=0.8.5:math/R-cran-dplyr \
		R-cran-generics>0:devel/R-cran-generics \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-pillar>=1.4.4:devel/R-cran-pillar \
		R-cran-pkgdown>=2.0.1:www/R-cran-pkgdown \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-tibble>=3.1.3:devel/R-cran-tibble \
		R-cran-waldo>=0.2.0:devel/R-cran-waldo \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-zeallot>0:devel/R-cran-zeallot

USES=		compiler:c++11-lang cran:auto-plist,compiles

MAKE_ENV=	LC_ALL=C.UTF-8

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
