# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	classInt
DISTVERSION=	0.2-3
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Choose Univariate Class Intervals

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-spData>=0.2.6.2:math/R-cran-spData \
		R-cran-e1071>0:science/R-cran-e1071
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
