PORTNAME=	qpdf
DISTVERSION=	1.4.1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Content-preserving transformations of PDF files
WWW=		https://cran.r-project.org/package=qpdf

LICENSE=	APACHE20

CRAN_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libqpdf.so:print/qpdf
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		compiler:c++17-lang cran:auto-plist,compiles jpeg pkgconfig

MAKE_ENV+=	EXTERNAL_QPDF=yes

.include <bsd.port.mk>
