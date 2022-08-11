PORTNAME=	hpx
DISTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Standard Library for Parallelism and Concurrency

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

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
CMAKE_TESTING_ON=	HPX_WITH_TESTS HPX_WITH_TESTS_UNIT # tests fail: https://github.com/STEllAR-GROUP/hpx/issues/5893

LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_gcc=	-latomic

BINARY_ALIAS=	git=false

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/LICENSE_1_0.txt
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
