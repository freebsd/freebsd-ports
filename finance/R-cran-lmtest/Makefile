# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmtest
DISTVERSION=	0.9-36
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Testing Linear Regression Models

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-zoo>=0:math/R-cran-zoo \
		R-cran-strucchange>0:finance/R-cran-strucchange \
		R-cran-sandwich>=2.2.4:math/R-cran-sandwich

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
