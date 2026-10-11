PORTNAME=	vdiffr
DISTVERSION=	1.0.9
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Visual Regression Testing and Graphical Diffing
WWW=		https://cran.r-project.org/package=vdiffr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-diffobj>0:devel/R-cran-diffobj \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-testthat>=3.0.3:devel/R-cran-testthat \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libpng16.so:graphics/png
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-decor>0:devel/R-cran-decor \
		R-cran-ggplot2>=3.2.0:graphics/R-cran-ggplot2 \
		R-cran-roxygen2>0:devel/R-cran-roxygen2 \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
