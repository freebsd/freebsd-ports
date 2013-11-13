# $FreeBSD$

PORTNAME=	ggplot2
PORTVERSION=	0.9.3.1
PORTREVISION=	4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Implementation of the Grammar of Graphics

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-plyr>=1.7.1:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-digest>=0:${PORTSDIR}/security/R-cran-digest \
		R-cran-gtable>=0.1.1:${PORTSDIR}/math/R-cran-gtable \
		R-cran-reshape2>=0:${PORTSDIR}/devel/R-cran-reshape2 \
		R-cran-scales>=0.2.3:${PORTSDIR}/graphics/R-cran-scales \
		R-cran-proto>=0:${PORTSDIR}/devel/R-cran-proto

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
