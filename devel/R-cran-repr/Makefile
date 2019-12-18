# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	repr
PORTVERSION=	1.0.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Serializable Reprensentations

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-pillar>=1.4.0:devel/R-cran-pillar \
		R-cran-base64enc>0:converters/R-cran-base64enc
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
