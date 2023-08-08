PORTNAME=	purrr
PORTVERSION=	1.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Functional Programming Tools
WWW=		https://cran.r-project.org/web/packages/purrr/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>=1.5.0:devel/R-cran-magrittr \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-vctrs>=0.5.0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
