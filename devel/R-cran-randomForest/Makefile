# $FreeBSD$

PORTNAME=	randomForest
DISTVERSION=	4.6-7
PORTREVISION=	4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Classification based on a forest of trees using random inputs

RUN_DEPENDS=	R-cran-RColorBrewer>=1.0.5_6:${PORTSDIR}/graphics/R-cran-RColorBrewer

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
