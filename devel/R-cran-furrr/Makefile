PORTNAME=	furrr
DISTVERSION=	0.4.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	Apply mapping functions in parallel using futures
WWW=		https://furrr.futureverse.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-future>=1.70.0:devel/R-cran-future \
		R-cran-globals>=0.19.1:devel/R-cran-globals \
		R-cran-purrr>=1.2.1:devel/R-cran-purrr \
		R-cran-rlang>=1.1.7:devel/R-cran-rlang \
		R-cran-vctrs>=0.7.0:devel/R-cran-vctrs
TEST_DEPENDS=	R-cran-dplyr>=1.1.4:math/R-cran-dplyr \
		R-cran-parallelly>=1.46.1:devel/R-cran-parallelly \
		R-cran-testthat>=3.3.2:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
