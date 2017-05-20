# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bit64
DISTVERSION=	0.9-7
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	S3 Class for Vectors of 64bit Integers

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-bit>=1.1.12:devel/R-cran-bit
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
