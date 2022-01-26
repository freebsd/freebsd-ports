PORTNAME=	matplotplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ graphics library for data visualization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libopenblas.so:math/openblas \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake compiler:c++17-lang jpeg

USE_GITHUB=	yes
GH_ACCOUNT=	alandefreitas

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS

.include <bsd.port.mk>
