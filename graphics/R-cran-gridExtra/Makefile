# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gridExtra
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Miscellaneous Functions for "Grid" Graphics

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-gtable>0:math/R-cran-gtable
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
