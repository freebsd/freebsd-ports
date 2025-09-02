PORTNAME=	ragg
DISTVERSION=	1.5.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Graphic Devices Based on AGG
WWW=		https://ragg.r-lib.org/

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.note
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-systemfonts>=1.0.3:devel/R-cran-systemfonts \
		R-cran-textshaping>=0.3.0:print/R-cran-textshaping
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjpeg.so:graphics/jpeg-turbo \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libwebpmux.so:graphics/webp
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>3.0.0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
