# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	doParallel
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Foreach parallel adaptor for the parallel package

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-foreach>=1.2.0:devel/R-cran-foreach \
		R-cran-iterators>=1.0.0:devel/R-cran-iterators
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
