# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	bindrcpp
DISTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Rcpp Interface to Active Bindings

BUILD_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-bindr>=0:devel/R-cran-bindr \
		R-cran-plogr>=0:devel/R-cran-plogr
RUN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-bindr>=0:devel/R-cran-bindr \
		R-cran-plogr>=0:devel/R-cran-plogr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
