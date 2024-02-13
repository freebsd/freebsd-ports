PORTNAME=	hpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4a61c0bb764616a103900f948ac9735b3b73e594.diff:-p1 # fix for https://github.com/STEllAR-GROUP/hpx/issues/6316

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Standard Library for Parallelism and Concurrency
WWW=		https://hpx.stellar-group.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_i386=	compilation fails: detail/tagged_ptr_pair.hpp:117:27: error: no matching function for call to 'bit_cast', see https://github.com/STEllAR-GROUP/hpx/issues/6426
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
CMAKE_TESTING_TARGET=	tests test

LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_gcc=	-latomic

BINARY_ALIAS=	git=false

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/LICENSE_1_0.txt
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
