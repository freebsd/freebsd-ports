PORTNAME=	sparsevctrs
DISTVERSION=	0.3.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Sparse Vectors for Use in Data Frames
WWW=		https://cran.r-project.org/package=sparsevctrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-vctrs>0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
