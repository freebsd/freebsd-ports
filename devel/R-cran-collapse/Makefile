PORTNAME=	collapse
PORTVERSION=	1.9.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced and Fast Data Transformation
WWW=		https://cran.r-project.org/web/packages/collapse/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
