# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strucchange
DISTVERSION=	1.5-2
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Testing, Monitoring, and Dating Structural Changes

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-zoo>0:math/R-cran-zoo \
		R-cran-sandwich>0:math/R-cran-sandwich
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
