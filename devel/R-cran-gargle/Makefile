PORTNAME=	gargle
DISTVERSION=	1.6.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Utilities for Working with Google APIs
WWW=		https://gargle.r-lib.org/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>=3.0.1:devel/R-cran-cli \
		R-cran-fs>=1.3.1:filesystems/R-cran-fs \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-httr>=1.4.5:www/R-cran-httr \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-sodium>0:security/R-cran-sodium \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=3.1.7:devel/R-cran-testthat

USES=		cran:auto-plist

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
