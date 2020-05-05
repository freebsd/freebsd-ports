# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foreach
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Foreach looping construct for R

LICENSE=	APACHE20

CRAN_DEPENDS=	R-cran-iterators>0:devel/R-cran-iterators
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
