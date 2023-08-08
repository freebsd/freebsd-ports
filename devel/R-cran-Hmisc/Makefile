PORTNAME=	Hmisc
DISTVERSION=	4.7-0
PORTREVISION=	2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Harrell Miscellaneous functions useful for data analysis
WWW=		https://cran.r-project.org/web/packages/Hmisc/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-latticeExtra>0:graphics/R-cran-latticeExtra \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra \
		R-cran-viridis>0:graphics/R-cran-viridis \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-htmlTable>0:textproc/R-cran-htmlTable \
		R-cran-Formula>0:math/R-cran-Formula
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
