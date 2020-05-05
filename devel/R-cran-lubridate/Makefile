# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lubridate
PORTVERSION=	1.7.8
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Make Dealing with Dates a Little Easier

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-generics>0:devel/R-cran-generics \
		R-cran-Rcpp>=0.12.13:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
