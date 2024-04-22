PORTNAME=	gargle
DISTVERSION=	1.5.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Utilities for Working with Google APIs
WWW=		https://gargle.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.0.1:devel/R-cran-cli \
		R-cran-fs>=1.3.1:sysutils/R-cran-fs \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-httr>=1.4.5:www/R-cran-httr \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
