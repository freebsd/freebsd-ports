# $FreeBSD$

PORTNAME=	scales
PORTVERSION=	0.2.5
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Scale functions for graphics

LICENSE=	MIT

RUN_DEPENDS=	R-cran-RColorBrewer>0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		R-cran-dichromat>0:${PORTSDIR}/graphics/R-cran-dichromat \
		R-cran-plyr>0:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-munsell>=0.2:${PORTSDIR}/graphics/R-cran-munsell \
		R-cran-labeling>0:${PORTSDIR}/math/R-cran-labeling \
		R-cran-Rcpp>0:${PORTSDIR}/devel/R-cran-Rcpp

USES=	cran:auto-plist

.include <bsd.port.mk>
