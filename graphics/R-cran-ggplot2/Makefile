# $FreeBSD$

PORTNAME=	ggplot2
PORTVERSION=	0.9.2
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An implementation of the Grammar of Graphics

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-plyr>=1.0:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-digest>=0:${PORTSDIR}/security/R-cran-digest \
		R-cran-gtable>=0.1.1:${PORTSDIR}/math/R-cran-gtable \
		R-cran-reshape2>=0:${PORTSDIR}/devel/R-cran-reshape2 \
		R-cran-scales>=0.2.2:${PORTSDIR}/graphics/R-cran-scales \
		R-cran-memoise>=0:${PORTSDIR}/devel/R-cran-memoise \
		R-cran-proto>=0:${PORTSDIR}/devel/R-cran-proto

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
