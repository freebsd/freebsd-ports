PORTNAME=	scales
PORTVERSION=	1.3.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Scale functions for graphics
WWW=		https://cran.r-project.org/web/packages/scales/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-farver>=2.0.3:graphics/R-cran-farver \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-labeling>0:math/R-cran-labeling \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-munsell>=0.5:graphics/R-cran-munsell \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-viridisLite>0:graphics/R-cran-viridisLite

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
