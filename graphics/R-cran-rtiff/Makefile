# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtiff
PORTVERSION=	1.4.7
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	TIFF reader for R

LICENSE=	GPLv3

LIB_DEPENDS=	libtiff.so:graphics/tiff
CRAN_DEPENDS=	R-cran-pixmap>0:graphics/R-cran-pixmap
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
