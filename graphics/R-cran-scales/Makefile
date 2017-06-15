# $FreeBSD$

PORTNAME=	scales
PORTVERSION=	0.4.1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Scale functions for graphics

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-dichromat>0:graphics/R-cran-dichromat \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-munsell>=0.2:graphics/R-cran-munsell \
		R-cran-labeling>0:math/R-cran-labeling \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
