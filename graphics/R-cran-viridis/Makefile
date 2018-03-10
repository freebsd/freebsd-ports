# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	viridis
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Default Color Maps from 'matplotlib'

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-viridisLite>=0.2.0:graphics/R-cran-viridisLite \
		R-cran-ggplot2>=1.0.1:graphics/R-cran-ggplot2 \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
