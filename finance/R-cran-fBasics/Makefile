# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	fBasics
PORTVERSION=	3011.87
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Markets and Basic Statistics

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-timeSeries>=2100.84:finance/R-cran-timeSeries \
		R-cran-stabledist>0:math/R-cran-stabledist \
		R-cran-gss>0:math/R-cran-gss

USES=	cran:auto-plist

.include <bsd.port.mk>
