# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantmod
DISTVERSION=	0.4.17
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Quantitative Financial Modelling and Trading Framework for R

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-xts>=0.9.0:math/R-cran-xts \
		R-cran-zoo>0:math/R-cran-zoo \
		R-cran-TTR>=0.2:finance/R-cran-TTR \
		R-cran-curl>0:ftp/R-cran-curl
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
