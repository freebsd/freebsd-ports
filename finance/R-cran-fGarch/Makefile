# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	fGarch
PORTVERSION=	2150.81
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedastic Modelling

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>0:${PORTSDIR}/finance/R-cran-timeDate \
		R-cran-timeSeries>0:${PORTSDIR}/finance/R-cran-timeSeries \
		R-cran-fBasics>=2100.78:${PORTSDIR}/finance/R-cran-fBasics

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
