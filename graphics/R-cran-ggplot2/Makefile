# New ports collection makefile for:	R-cran-ggplot2
# Date created:		2011-09-10
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ggplot2
PORTVERSION=	0.9.1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An implementation of the Grammar of Graphics

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-plyr>=1.0:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-digest>=0:${PORTSDIR}/security/R-cran-digest \
		R-cran-reshape2>=0:${PORTSDIR}/devel/R-cran-reshape2 \
		R-cran-scales>=0.2.1:${PORTSDIR}/graphics/R-cran-scales \
		R-cran-memoise>=0:${PORTSDIR}/devel/R-cran-memoise \
		R-cran-proto>=0:${PORTSDIR}/devel/R-cran-proto

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
