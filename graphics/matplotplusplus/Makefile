PORTNAME=	matplotplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ graphics library for data visualization
WWW=		https://alandefreitas.github.io/matplotplusplus/ \
		https://github.com/alandefreitas/matplotplusplus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libopenblas.so:math/openblas \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake:testing compiler:c++17-lang jpeg
USE_WX=		3.2+

USE_GITHUB=	yes
GH_ACCOUNT=	alandefreitas

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING MATPLOTPP_BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING MATPLOTPP_BUILD_TESTS MATPLOTPP_BUILD_EXAMPLES

# tests as of 1.2.2: 100% tests passed, 0 tests failed out of 545 (tests need ENTER to be pressed for them to proceed, see https://github.com/alandefreitas/matplotplusplus/issues/478)

.include <bsd.port.mk>
