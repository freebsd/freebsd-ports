# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rgexf
PORTVERSION=	0.15.3
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Build, Import and Export GEXF Graph Files

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-XML>0:textproc/R-cran-XML \
		R-cran-Rook>0:www/R-cran-Rook \
		R-cran-igraph>0:math/R-cran-igraph
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
