PORTNAME=	patchwork
DISTVERSION=	1.3.2
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	Compose ggplot2 plots into the same graphic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-farver>0:graphics/R-cran-farver \
		R-cran-ggplot2>=3.0.0:graphics/R-cran-ggplot2 \
		R-cran-gtable>=0.3.6:math/R-cran-gtable \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang
TEST_DEPENDS=	R-cran-testthat>=2.1.0:devel/R-cran-testthat \
		R-cran-vdiffr>0:devel/R-cran-vdiffr

USES=		cran:auto-plist

.include <bsd.port.mk>
