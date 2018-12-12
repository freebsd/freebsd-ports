# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tidyselect
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Select from a Set of Strings

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rlang>=0.2.2:devel/R-cran-rlang \
		R-cran-Rcpp>=0.12.0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
