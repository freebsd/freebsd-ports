PORTNAME=	glmnet
DISTVERSION=	5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lasso and elastic-net regularized generalized linear models
WWW=		https://cran.r-project.org/web/packages/glmnet/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-foreach>=0:devel/R-cran-foreach \
		R-cran-shape>=0:devel/R-cran-shape \
		R-cran-Rcpp>=0:devel/R-cran-Rcpp \
		R-cran-RcppEigen>=0:math/R-cran-RcppEigen
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
