# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	tseries
DISTVERSION=	0.10-29
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Time series analysis and computational finance

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-quadprog>0:${PORTSDIR}/math/R-cran-quadprog \
		R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
