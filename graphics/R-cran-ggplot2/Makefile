# New ports collection makefile for:	R-cran-ggplot2
# Date created:		2011-09-10
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ggplot2
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An implementation of the Grammar of Graphics

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-reshape>=0.8.0:${PORTSDIR}/devel/R-cran-reshape \
		R-cran-proto>0:${PORTSDIR}/devel/R-cran-proto \
		R-cran-plyr>0:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-RColorBrewer>0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		R-cran-digest>0:${PORTSDIR}/security/R-cran-digest \
		R-cran-colorspace>0:${PORTSDIR}/graphics/R-cran-colorspace

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
