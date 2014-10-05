# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantmod
DISTVERSION=	0.4-1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Quantitative Financial Modelling and Trading Framework for R

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-xts>=0.9.0:${PORTSDIR}/math/R-cran-xts \
		R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-TTR>=0.2:${PORTSDIR}/finance/R-cran-TTR

USES=	cran:auto-plist

OPTIONS_DEFINE=	DEFAULT
DEFAULT_DESC=	Run with R-cran-Default
DEFAULT_RUN_DEPENDS=	R-cran-Default>0:${PORTSDIR}/devel/R-cran-Defaults

OPTIONS_DEFAULT=	DEFAULT

.include <bsd.port.mk>
