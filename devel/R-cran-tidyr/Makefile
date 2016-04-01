# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tidyr
PORTVERSION=	0.4.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily tidy data with spread and gather functions

LICENSE=	MIT

RUN_DEPENDS=	R-cran-dplyr>=0.4:math/R-cran-dplyr \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-lazyeval>0:math/R-cran-lazyeval \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp

USES=	cran:auto-plist

.include <bsd.port.mk>
