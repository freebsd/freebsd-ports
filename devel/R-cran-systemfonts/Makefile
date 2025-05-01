PORTNAME=	systemfonts
DISTVERSION=	1.2.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	System Native Font Finding
WWW=		https://systemfonts.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-cpp11>=0.2.1:devel/R-cran-cpp11 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-farver>0:graphics/R-cran-farver \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype

USES=		cran:auto-plist,compiles pkgconfig

TESTING_UNSAFE=	Test is non-deterministic, see also https://github.com/r-lib/systemfonts/pull/130

.include <bsd.port.mk>
