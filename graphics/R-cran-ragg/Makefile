PORTNAME=	ragg
DISTVERSION=	1.3.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Graphic Devices Based on AGG
WWW=		https://ragg.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-systemfonts>=1.0.3:devel/R-cran-systemfonts \
		R-cran-textshaping>=0.3.0:print/R-cran-textshaping
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjpeg.so:graphics/jpeg-turbo \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
