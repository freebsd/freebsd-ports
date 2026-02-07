PORTNAME=	ids
DISTVERSION=	1.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Generate Random Identifiers
WWW=		https://github.com/richfitz/ids

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-openssl>0:security/R-cran-openssl \
		R-cran-uuid>0:devel/R-cran-uuid
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
