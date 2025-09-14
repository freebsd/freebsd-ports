PORTNAME=	pdftools
DISTVERSION=	3.6.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Utilities based on libpoppler
WWW=		https://cran.r-project.org/package=pdftools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-qpdf>0:graphics/R-cran-qpdf \
		R-cran-Rcpp>=0.12.12:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libpoppler-cpp.so:graphics/poppler
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-png>0:graphics/R-cran-png \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-webp>0:graphics/R-cran-webp

USES=		compiler:c++17-lang cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
