# New ports collection makefile for:	R-cran-diagram
# Date created:		2011-09-09
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diagram
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Functions for visualising simple graphs, plotting flow diagrams

RUN_DEPENDS=	R-cran-shape>0:${PORTSDIR}/graphics/R-cran-shape

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
