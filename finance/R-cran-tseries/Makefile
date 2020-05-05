# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	tseries
DISTVERSION=	0.10-45
PORTREVISION=	3
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time Series Analysis and Computational Finance

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-quantmod>=0.4.9:finance/R-cran-quantmod \
		R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
