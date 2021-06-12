PORTNAME=	benchmark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Microbenchmark support library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BENCHMARK_ENABLE_TESTING

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-thread-safety-analysis # workaround for https://github.com/google/benchmark/issues/655
CXXFLAGS_gcc=	-Wno-stringop-truncation
CXXFLAGS+=	-Wno-sign-compare # workaround for https://github.com/google/googletest/issues/1752

do-test: # Broken: https://github.com/google/benchmark/issues/979
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBENCHMARK_ENABLE_TESTING=ON -DGOOGLETEST_PATH=${LOCALBASE} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
