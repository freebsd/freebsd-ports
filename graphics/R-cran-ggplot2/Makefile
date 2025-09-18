PORTNAME=	ggplot2
PORTVERSION=	4.0.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Implementation of the Grammar of Graphics
WWW=		https://ggplot2.tidyverse.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-gtable>=0.1.1:math/R-cran-gtable \
		R-cran-isoband>0:math/R-cran-isoband \
		R-cran-lifecycle>=1.0.1:devel/R-cran-lifecycle \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-scales>=1.2.0:graphics/R-cran-scales \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-vctrs>=0.5.0:devel/R-cran-vctrs \
		R-cran-withr>=2.5.0:devel/R-cran-withr \
		R-cran-S7>=0:devel/R-cran-S7
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
