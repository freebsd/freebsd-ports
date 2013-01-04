# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	fBasics
PORTVERSION=	2160.85
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Markets and Basic Statistics

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-timeDate>0:${PORTSDIR}/finance/R-cran-timeDate \
		R-cran-timeSeries>=2100.84:${PORTSDIR}/finance/R-cran-timeSeries \
		R-cran-stabledist>0:${PORTSDIR}/math/R-cran-stabledist

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
