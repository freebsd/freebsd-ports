# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caTools
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools: moving window statistics, GIF, Base64, ROC AUC, etc

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-bitops>0:${PORTSDIR}/devel/R-cran-bitops

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
