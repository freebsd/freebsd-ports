PORTNAME=	hpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	5
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	03d01dc18987d9f080a4ff43dea7ac95ffdfa208.diff:-p1 # backport of https://github.com/STEllAR-GROUP/hpx/pull/6499
PATCHFILES+=	d3bb5b140cf82fa582c2549873b1ee36f41ab855.diff:-p1 # backport of https://github.com/STEllAR-GROUP/hpx/pull/6503

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Standard Library for Parallelism and Concurrency
WWW=		https://hpx.stellar-group.org/ \
		https://github.com/STEllAR-GROUP/hpx

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_armv7=	compilation fails: no matching function for call to 'bit_cast', see https://github.com/STEllAR-GROUP/hpx/issues/6557
BROKEN_i386=	compilation fails: detail/tagged_ptr_pair.hpp:117:27: error: no matching function for call to 'bit_cast', see https://github.com/STEllAR-GROUP/hpx/issues/6426
BROKEN_powerpc=	compilation fails: detail/tagged_ptr_pair.hpp:117:27: error: no matching function for call to 'bit_cast', see https://github.com/STEllAR-GROUP/hpx/issues/6426
BROKEN_riscv64=	hpx/hardware/timestamp.hpp:43:6: error: Unsupported platform

BUILD_DEPENDS=	asio>0:net/asio
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhwloc.so.15:devel/hwloc2

USES=		cmake:testing compiler:c++17-lang python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	STEllAR-GROUP

SHEBANG_FILES=	cmake/templates/hpxrun.py.in cmake/templates/hpxcxx.in
SHEBANG_GLOB=	*.py

CMAKE_ON=	HPX_WITH_GENERIC_CONTEXT_COROUTINES
CMAKE_OFF=	HPX_WITH_EXAMPLES HPX_WITH_TESTS HPX_WITH_TESTS_BENCHMARKS HPX_WITH_TESTS_REGRESSIONS HPX_WITH_TESTS_UNIT HPX_WITH_TESTS_EXAMPLES
CMAKE_TESTING_ON=	HPX_WITH_TESTS HPX_WITH_TESTS_UNIT # 6 tests fail, 4 tests time out, see https://github.com/STEllAR-GROUP/hpx/issues/6331
CMAKE_TESTING_TARGET=	test # tests are built in pre-test with the 'tests' target

LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_gcc=	-latomic

BINARY_ALIAS=	git=false

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/LICENSE_1_0.txt
	@${RMDIR} ${STAGEDIR}${DATADIR}

pre-test: # build tests with the 'tests' target
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_TESTING_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} tests

# 1 test, numa_allocator_test, fails, see https://github.com/STEllAR-GROUP/hpx/issues/6502

.include <bsd.port.mk>
