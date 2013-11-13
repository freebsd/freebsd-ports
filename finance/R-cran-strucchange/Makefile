# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strucchange
DISTVERSION=	1.4-7
PORTREVISION=	6
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Testing, Monitoring, and Dating Structural Changes

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-sandwich>0:${PORTSDIR}/math/R-cran-sandwich

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
