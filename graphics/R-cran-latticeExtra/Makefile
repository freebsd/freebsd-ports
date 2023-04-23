PORTNAME=	latticeExtra
DISTVERSION=	0.6-29
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Extra graphical utilities based on lattice
WWW=		https://cran.r-project.org/web/packages/latticeExtra/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-png>0:graphics/R-cran-png \
		R-cran-jpeg>0:graphics/R-cran-jpeg \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
