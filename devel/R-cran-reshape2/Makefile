# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reshape2
PORTVERSION=	1.4.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Flexibly reshape data: a reboot of the reshape package

LICENSE=	MIT

RUN_DEPENDS=	R-cran-plyr>=1.8.1:devel/R-cran-plyr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-stringr>0:textproc/R-cran-stringr

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
