# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tibble
PORTVERSION=	1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Data Frames

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-assertthat>0:math/R-cran-assertthat \
		R-cran-lazyeval>0.0.10:math/R-cran-lazyeval \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
