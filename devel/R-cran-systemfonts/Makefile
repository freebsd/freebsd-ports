PORTNAME=	systemfonts
DISTVERSION=	1.2.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	System Native Font Finding
WWW=		https://systemfonts.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cpp11>=0.2.1:devel/R-cran-cpp11 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat

TESTING_UNSAFE=	Test is non-deterministic
USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
