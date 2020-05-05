# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hms
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Pretty Time of Day

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>=0.2.1:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
