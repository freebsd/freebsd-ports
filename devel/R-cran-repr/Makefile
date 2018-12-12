# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	repr
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Serializable Reprensentations

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-base64enc>0:converters/R-cran-base64enc
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
