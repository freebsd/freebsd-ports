# New ports collection makefile for:	R-cran-maptools
# Date created:		2011-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maptools
DISTVERSION=	0.8-10
PORTREVISION=	1
CATEGORIES=	astro
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for reading and handling spatial objects

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-sp>=0.9.47:${PORTSDIR}/math/R-cran-sp

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
