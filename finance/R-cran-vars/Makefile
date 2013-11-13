# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vars
DISTVERSION=	1.5-2
PORTREVISION=	2
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	VAR Modelling

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-strucchange>0:${PORTSDIR}/finance/R-cran-strucchange \
		R-cran-urca>=1.1.6:${PORTSDIR}/finance/R-cran-urca \
		R-cran-lmtest>=0.9.26:${PORTSDIR}/finance/R-cran-lmtest \
		R-cran-sandwich>=2.2.4:${PORTSDIR}/math/R-cran-sandwich

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
