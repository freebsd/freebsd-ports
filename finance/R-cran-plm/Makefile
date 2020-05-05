# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plm
DISTVERSION=	2.2-3
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Linear Models for Panel Data

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-bdsmatrix>0:math/R-cran-bdsmatrix \
		R-cran-zoo>0:math/R-cran-zoo \
		R-cran-sandwich>0:math/R-cran-sandwich \
		R-cran-lmtest>0:finance/R-cran-lmtest \
		R-cran-maxLik>0:math/R-cran-maxLik \
		R-cran-Rdpack>0:devel/R-cran-Rdpack \
		R-cran-Formula>0:math/R-cran-Formula
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
