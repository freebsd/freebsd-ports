# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AER
DISTVERSION=	1.2-4
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Applied Econometrics with R

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-car>=2.0.1:math/R-cran-car \
		R-cran-lmtest>=0:finance/R-cran-lmtest \
		R-cran-Formula>=0.2.0:math/R-cran-Formula \
		R-cran-zoo>=0:math/R-cran-zoo

USES=	cran:auto-plist

.include <bsd.port.mk>
