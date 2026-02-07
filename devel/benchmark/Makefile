PORTNAME=	benchmark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.4
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Microbenchmark support library
WWW=		https://github.com/google/benchmark

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BENCHMARK_ENABLE_TESTING BENCHMARK_USE_BUNDLED_GTEST
CMAKE_TESTING_ON=	BENCHMARK_ENABLE_TESTING # BENCHMARK_DOWNLOAD_DEPENDENCIES

CFLAGS+=	-Wno-error=sign-conversion
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_gcc=	-Wno-stringop-truncation
PIE_UNSAFE=	yes

BINARY_ALIAS=	git=false

PLIST_SUB=	VERSION=${DISTVERSION}

# tests as of 1.9.4: 100% tests passed, 0 tests failed out of 82

.include <bsd.port.mk>
