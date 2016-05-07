# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plm
DISTVERSION=	1.5-12
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Linear Models for Panel Data

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-Formula>=0.2.0:math/R-cran-Formula \
		R-cran-bdsmatrix>0:math/R-cran-bdsmatrix \
		R-cran-zoo>0:math/R-cran-zoo \
		R-cran-sandwich>0:math/R-cran-sandwich \
		R-cran-car>0:math/R-cran-car \
		R-cran-lmtest>0:finance/R-cran-lmtest

USES=	cran:auto-plist

.include <bsd.port.mk>
