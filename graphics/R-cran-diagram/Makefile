# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	diagram
PORTVERSION=	1.6.4
PORTREVISION=	4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Functions for visualising simple graphs, plotting flow diagrams

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-shape>0:graphics/R-cran-shape
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
