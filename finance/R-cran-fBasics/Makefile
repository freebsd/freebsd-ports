# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	fBasics
PORTVERSION=	3010.86
PORTREVISION=	4
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Markets and Basic Statistics

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>0:${PORTSDIR}/finance/R-cran-timeDate \
		R-cran-timeSeries>=2100.84:${PORTSDIR}/finance/R-cran-timeSeries \
		R-cran-stabledist>0:${PORTSDIR}/math/R-cran-stabledist \
		R-cran-gss>0:${PORTSDIR}/math/R-cran-gss

USES=	cran:auto-plist

.include <bsd.port.mk>
