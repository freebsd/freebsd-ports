PORTNAME=	testthat
DISTVERSION=	3.2.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unit Testing for R
WWW=		https://testthat.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-brio>=1.1.3:devel/R-cran-brio \
		R-cran-callr>=3.7.3:devel/R-cran-callr \
		R-cran-cli>=3.6.1:devel/R-cran-cli \
		R-cran-desc>=1.4.2:devel/R-cran-desc \
		R-cran-digest>=0.6.33:security/R-cran-digest \
		R-cran-evaluate>=1.0.1:devel/R-cran-evaluate \
		R-cran-jsonlite>=1.8.7:converters/R-cran-jsonlite \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>=2.0.3:devel/R-cran-magrittr \
		R-cran-pkgload>=1.3.2.1:devel/R-cran-pkgload \
		R-cran-praise>=1.0.0:devel/R-cran-praise \
		R-cran-processx>=3.8.2:sysutils/R-cran-processx \
		R-cran-ps>=1.7.5:sysutils/R-cran-ps \
		R-cran-R6>=2.5.1:devel/R-cran-R6 \
		R-cran-rlang>=1.1.1:devel/R-cran-rlang \
		R-cran-waldo>=0.6.0:devel/R-cran-waldo \
		R-cran-withr>=3.0.2:devel/R-cran-withr

USES=		cran:auto-plist,compiles

TESTING_UNSAFE=	https://github.com/r-lib/testthat/issues/2214

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
