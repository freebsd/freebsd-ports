# $FreeBSD$

PORTNAME=	promises
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Abstractions for Promise-Based Asynchronous Programming

LICENSE=	MIT

USES=		cran:auto-plist,compiles

CRAN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-later>0:devel/R-cran-later \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

.include <bsd.port.mk>
