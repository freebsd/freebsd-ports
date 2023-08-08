PORTNAME=	pROC
PORTVERSION=	1.18.4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Display and Analyze ROC Curves
WWW=		https://cran.r-project.org/web/packages/pROC/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-Rcpp>=0.11.1:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
