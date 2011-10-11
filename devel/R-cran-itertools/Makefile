# New ports collection makefile for:	R-cran-itertools
# Date created:		2011-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	itertools
DISTVERSION=	0.1-1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Iterator Tools for R

RUN_DEPENDS=	R-cran-iterators>=1.0.0:${PORTSDIR}/devel/R-cran-iterators

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
