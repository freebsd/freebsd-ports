# $FreeBSD$

PORTNAME=	scales
PORTVERSION=	0.2.3
PORTREVISION=	6
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Scale functions for graphics

LICENSE=	MIT

RUN_DEPENDS=	R-cran-RColorBrewer>=0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		R-cran-stringr>=0:${PORTSDIR}/textproc/R-cran-stringr \
		R-cran-dichromat>=0:${PORTSDIR}/graphics/R-cran-dichromat \
		R-cran-munsell>=0.2:${PORTSDIR}/graphics/R-cran-munsell \
		R-cran-plyr>=1.2:${PORTSDIR}/devel/R-cran-plyr \
		R-cran-labeling>=0:${PORTSDIR}/math/R-cran-labeling

USES=	cran:auto-plist

.include <bsd.port.mk>
