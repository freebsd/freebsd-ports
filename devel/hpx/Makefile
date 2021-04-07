PORTNAME=	hpx
DISTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Standard Library for Parallelism and Concurrency

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_riscv64=		fails to compile: hpx/util/hardware/timestamp.hpp:43:6: error: Unsupported platform

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhwloc.so.15:devel/hwloc2

USES=		cmake compiler:c++17-lang python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	STEllAR-GROUP
SHEBANG_FILES=	cmake/templates/hpxrun.py.in cmake/templates/hpxcxx.in python/scripts/*.py
USE_LDCONFIG=	yes

CMAKE_ON=	HPX_WITH_GENERIC_CONTEXT_COROUTINES
CMAKE_OFF=	HPX_WITH_EXAMPLES HPX_WITH_TESTS
LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_gcc=	-latomic

.include <bsd.port.mk>
