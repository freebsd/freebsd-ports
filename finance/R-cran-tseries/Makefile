# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	tseries
DISTVERSION=	0.10-35
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Time series analysis and computational finance

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-zoo>0:math/R-cran-zoo
RUN_DEPENDS=	R-cran-quadprog>0:math/R-cran-quadprog \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:compiles

.include <bsd.port.mk>
