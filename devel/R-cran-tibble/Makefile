# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tibble
PORTVERSION=	1.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-assertthat>0:math/R-cran-assertthat \
		R-cran-lazyeval>0.1.10:math/R-cran-lazyeval \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
