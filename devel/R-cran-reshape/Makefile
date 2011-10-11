# New ports collection makefile for:	R-cran-reshape
# Date created:		2011-08-30
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reshape
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An R package for flexibly restructuring and aggregating data

LICENSE=	MIT

RUN_DEPENDS=	R-cran-plyr>0:${PORTSDIR}/devel/R-cran-plyr

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
