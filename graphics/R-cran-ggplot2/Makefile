PORTNAME=	ggplot2
PORTVERSION=	3.3.5
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Implementation of the Grammar of Graphics

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-gtable>=0.1.1:math/R-cran-gtable \
		R-cran-isoband>0:math/R-cran-isoband \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-scales>=0.5.0:graphics/R-cran-scales \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-withr>=2.0.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
