# $FreeBSD$

PORTNAME=	ggplot2
PORTVERSION=	2.1.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Implementation of the Grammar of Graphics

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-digest>=0:${PORTSDIR}/security/R-cran-digest \
		R-cran-gtable>=0.1.1:${PORTSDIR}/math/R-cran-gtable \
		R-cran-plyr>=1.7.1:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-reshape2>=0:${PORTSDIR}/devel/R-cran-reshape2 \
		R-cran-scales>=0.3.0:${PORTSDIR}/graphics/R-cran-scales

USES=	cran:auto-plist

.include <bsd.port.mk>
