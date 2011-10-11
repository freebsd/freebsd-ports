# New ports collection makefile for:	R-cran-foreach
# Date created:		2011-09-04
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foreach
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Foreach looping construct for R

LICENSE=	ASL

RUN_DEPENDS=	R-cran-iterators>=1.0.0:${PORTSDIR}/devel/R-cran-iterators

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
