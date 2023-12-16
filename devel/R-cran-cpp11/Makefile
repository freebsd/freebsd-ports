PORTNAME=	cpp11
DISTVERSION=	0.4.7
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++11 Interface for R's C Interface
WWW=		https://cran.r-project.org/web/packages/cpp11/

LICENSE=	MIT

TEST_DEPENDS=	R-cran-decor>0:devel/R-cran-decor \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-progress>0:devel/R-cran-progress \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		compiler:c++11-lang cran:auto-plist

.include <bsd.port.mk>
