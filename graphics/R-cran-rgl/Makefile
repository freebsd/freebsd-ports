PORTNAME=	rgl
DISTVERSION=	1.3.31
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	3D Visualization Using OpenGL
WWW=		https://cran.r-project.org/package=${PORTNAME}

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>=1.6.0:www/R-cran-htmlwidgets \
		R-cran-jsonlite>=0.9.20:converters/R-cran-jsonlite \
		R-cran-knitr>=1.33:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-R6>0:devel/R-cran-R6
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-crosstalk>0:www/R-cran-crosstalk \
		R-cran-deldir>=1.0.4:math/R-cran-deldir \
		R-cran-downlit>=0.4.0:textproc/R-cran-downlit \
		R-cran-interp>0:devel/R-cran-interp \
		R-cran-jpeg>0:graphics/R-cran-jpeg \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-misc3d>0:math/R-cran-misc3d \
		R-cran-pkgdown>=2.0.0:www/R-cran-pkgdown \
		R-cran-png>0:graphics/R-cran-png \
		R-cran-rmarkdown>=2.16:textproc/R-cran-rmarkdown \
		R-cran-shiny>0:www/R-cran-shiny \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		compiler:c++17-lang cran:auto-plist,compiles gl xorg
USE_GL=		gl glu
USE_XORG=	x11

TESTING_UNSAFE=	Requires a WebGL-capable browser

.include <bsd.port.mk>
