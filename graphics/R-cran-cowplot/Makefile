PORTNAME=	cowplot
DISTVERSION=	1.2.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Streamlined Plot Theme and Plot Annotations for 'ggplot2'
WWW=		https://wilkelab.org/cowplot/

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-ggplot2>=3.5.2:graphics/R-cran-ggplot2 \
		R-cran-gtable>0:math/R-cran-gtable \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-scales>0:graphics/R-cran-scales
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-forcats>0:math/R-cran-forcats \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-maps>0:math/R-cran-maps \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-testthat>=1.0.0:devel/R-cran-testthat \
		R-cran-tidyr>0:devel/R-cran-tidyr

USES=		cran:auto-plist

.include <bsd.port.mk>
