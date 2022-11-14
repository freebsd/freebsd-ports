PORTNAME=	benchmark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Microbenchmark support library
WWW=		https://github.com/google/benchmark

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	google:googletest:release-1.12.1:googletest # requires googletest sources for some reason, see https://github.com/google/benchmark/issues/979

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BENCHMARK_ENABLE_TESTING
CMAKE_TESTING_ON=	BENCHMARK_ENABLE_TESTING # BENCHMARK_DOWNLOAD_DEPENDENCIES
CMAKE_TESTING_ARGS=	-DGOOGLETEST_PATH=${WRKSRC_googletest}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_gcc=	-Wno-stringop-truncation

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
