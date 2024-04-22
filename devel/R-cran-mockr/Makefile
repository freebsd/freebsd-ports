PORTNAME=	mockr
DISTVERSION=	0.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Mocking in R
WWW=		https://krlmlr.github.io/mockr/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
