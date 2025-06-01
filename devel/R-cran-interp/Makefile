PORTNAME=	interp
DISTVERSION=	1.1-6
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Interpolation methods
WWW=		https://cran.r-project.org/web/packages/interp/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-deldir>0:math/R-cran-deldir \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-RcppEigen>0:math/R-cran-RcppEigen
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

#USES=		compiler:c++11-lang cran:auto-plist,compiles
USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
