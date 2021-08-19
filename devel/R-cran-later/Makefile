PORTNAME=	later
PORTVERSION=	1.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Utilities for Delaying Function Execution

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-Rcpp>=0.12.9:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
