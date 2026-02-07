PORTNAME=	conflicted
DISTVERSION=	1.2.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Alternative Conflict Resolution Strategy
WWW=		https://conflicted.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
