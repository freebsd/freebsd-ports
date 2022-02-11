PORTNAME=	collapse
PORTVERSION=	1.7.6
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Advanced and Fast Data Transformation

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
