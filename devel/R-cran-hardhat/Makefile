PORTNAME=	hardhat
DISTVERSION=	1.4.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Construct Modeling Packages
WWW=		https://cran.r-project.org/web/packages/hardhat/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-tibble>=3.2.1:devel/R-cran-tibble \
		R-cran-vctrs>=0.6.0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-recipes>0:math/R-cran-recipes \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
