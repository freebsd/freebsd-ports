# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	fGarch
PORTVERSION=	3010.82
PORTREVISION=	5
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedastic Modelling

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-timeSeries>0:finance/R-cran-timeSeries \
		R-cran-fBasics>=2100.78:finance/R-cran-fBasics

USES=	cran:auto-plist

.include <bsd.port.mk>
