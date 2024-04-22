PORTNAME=	cowplot
DISTVERSION=	1.1.3
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Streamlined Plot Theme and Plot Annotations for 'ggplot2'
WWW=		https://wilkelab.org/cowplot/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-ggplot2>=3.4.0:graphics/R-cran-ggplot2 \
		R-cran-gtable>0:math/R-cran-gtable \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-scales>0:graphics/R-cran-scales
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-dbplyr>0:databases/R-cran-dbplyr \
		R-cran-maps>0:math/R-cran-maps \
		R-cran-testthat>=1.0.0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
