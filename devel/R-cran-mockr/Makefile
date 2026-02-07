PORTNAME=	mockr
DISTVERSION=	0.2.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Mocking in R
WWW=		https://krlmlr.github.io/mockr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

TESTING_UNSAFE=	https://github.com/krlmlr/mockr/issues/59

.include <bsd.port.mk>
