PORTNAME=	tweenr
DISTVERSION=	2.0.3
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Interpolate Data for Smooth Animations
WWW=		https://cran.r-project.org/package=tweenr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cpp11>=0.4.2:devel/R-cran-cpp11 \
		R-cran-farver>0:graphics/R-cran-farver \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
