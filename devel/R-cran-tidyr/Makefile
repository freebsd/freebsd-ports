# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tidyr
PORTVERSION=	0.6.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily tidy data with spread and gather functions

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-dplyr>=0.4:math/R-cran-dplyr \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-lazyeval>0:math/R-cran-lazyeval \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
