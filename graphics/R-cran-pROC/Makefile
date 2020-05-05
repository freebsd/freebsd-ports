# $FreeBSD$

PORTNAME=	pROC
PORTVERSION=	1.16.2
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Display and Analyze ROC Curves

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-Rcpp>=0.11.1:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
