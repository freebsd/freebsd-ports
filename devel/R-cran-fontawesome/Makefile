PORTNAME=	fontawesome
DISTVERSION=	0.5.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Easily Work with 'Font Awesome' Icons
WWW=		https://cran.r-project.org/web/packages/fontawesome/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>=1.0.6:devel/R-cran-rlang \
		R-cran-htmltools>=0.5.1.1:textproc/R-cran-htmltools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
