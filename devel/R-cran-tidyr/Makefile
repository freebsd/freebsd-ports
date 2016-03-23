# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tidyr
PORTVERSION=	0.4.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily tidy data with spread and gather functions

LICENSE=	MIT

RUN_DEPENDS=	R-cran-dplyr>=0.4:${PORTSDIR}/math/R-cran-dplyr \
		R-cran-stringi>0:${PORTSDIR}/textproc/R-cran-stringi \
		R-cran-lazyeval>0:${PORTSDIR}/math/R-cran-lazyeval \
		R-cran-magrittr>0:${PORTSDIR}/devel/R-cran-magrittr \
		R-cran-Rcpp>0:${PORTSDIR}/devel/R-cran-Rcpp

USES=	cran:auto-plist

.include <bsd.port.mk>
