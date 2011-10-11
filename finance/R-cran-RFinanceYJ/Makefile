# New ports collection makefile for:	R-cran-RFinanceYJ
# Date created:		2011-08-06
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	RFinanceYJ
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	finance
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Japanese stock market from Yahoo!-finance-Japan

LICENSE=	BSD

RUN_DEPENDS=	R-cran-XML>0:${PORTSDIR}/textproc/R-cran-XML \
		R-cran-xts>0:${PORTSDIR}/math/R-cran-xts

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
