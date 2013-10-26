# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmtest
DISTVERSION=	0.9-31
PORTREVISION=	2
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Testing Linear Regression Models

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-zoo>=0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-strucchange>0:${PORTSDIR}/finance/R-cran-strucchange \
		R-cran-sandwich>=2.2.4:${PORTSDIR}/math/R-cran-sandwich

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
