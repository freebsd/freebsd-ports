PORTNAME=	pykep
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library providing basic tools for astrodynamics research
WWW=		https://esa.github.io/pykep/ \
		https://github.com/esa/pykep

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xtensor>0:math/xtensor \
		xtensor-blas>0:math/xtensor-blas
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libheyoka.so:math/heyoka \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmp++.so:math/mppp \
		libopenblas.so:math/openblas \
		libspdlog.so:devel/spdlog
TEST_DEPENDS=	pagmo2>0:science/pagmo2

USES=		cmake:testing compiler:c++23-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	kep3_BUILD_TESTS
CMAKE_TESTING_ON=	kep3_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	esa

# tests as of 3.0.0: 97% tests passed, 1 tests failed out of 29, see https://github.com/esa/pykep/issues/198

.include <bsd.port.mk>
