PORTNAME=	cpp11
DISTVERSION=	0.4.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++11 Interface for R's C Interface
WWW=		https://cran.r-project.org/web/packages/cpp11/

LICENSE=	MIT

TEST_DEPENDS=	R-cran-decor>0:devel/R-cran-decor \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-testthat>0:devel/R-cran-testthat
# Test failure: https://github.com/r-lib/cpp11/issues/323

USES=		compiler:c++11-lang cran:auto-plist

.include <bsd.port.mk>
