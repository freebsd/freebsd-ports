PORTNAME=	ggforce
DISTVERSION=	0.5.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Accelerating ggplot2
WWW=		https://cran.r-project.org/package=${PORTNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-ggplot2>=3.5.0:graphics/R-cran-ggplot2 \
		R-cran-gtable>0:math/R-cran-gtable \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-polyclip>0:math/R-cran-polyclip \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-scales>0:graphics/R-cran-scales \
		R-cran-systemfonts>0:devel/R-cran-systemfonts \
		R-cran-tidyselect>0:devel/R-cran-tidyselect \
		R-cran-tweenr>=0.1.5:graphics/R-cran-tweenr \
		R-cran-vctrs>0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-deldir>0:math/R-cran-deldir \
		R-cran-reshape2>0:devel/R-cran-reshape2 \
		R-cran-sessioninfo>0:devel/R-cran-sessioninfo \
		R-cran-units>=0.8.0:math/R-cran-units

USES=		compiler:c++17-lang cran:auto-plist,compiles
USE_GCC=	yes

.include <bsd.port.mk>
