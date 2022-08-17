PORTNAME=	halide
DISTVERSIONPREFIX=	v
DISTVERSION=	14.0.0
PORTEPOCH=	1
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for fast and portable data-parallel computation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=		fails to build: /usr/include/c++/v1/__config:1141:6: No thread API

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION} # because halide expects LLVMConfig.cmake
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

USES=		cmake:testing # one test (test_apps_autoscheduler) hangs
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	Halide

LLVM_VERSION=	14 # last supported llvm

# use the same compiler that devel/llvmNN installs
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}

CMAKE_ARGS=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VERSION}/lib/cmake/llvm
CMAKE_ON=	LLVM_USE_SHARED_LLVM_LIBRARY HALIDE_SHARED_LIBRARY \
		Halide_SHARED_LLVM
CMAKE_OFF=	WITH_PYTHON_BINDINGS WITH_APPS WITH_TUTORIALS WITH_DOCS WITH_TESTS # APPS are demos
CMAKE_OFF+=	Halide_WITH_INTROSPECTION # missing program_invocation_name variable, see https://github.com/halide/Halide/issues/6945#issuecomment-1217146679
CMAKE_OFF+=	WITH_WABT # fetches wabt (when www/wabt is available)

OPTIONS_DEFINE=	NATIVE
OPTIONS_DEFAULT=

NATIVE_DESC=	Build with native optimizations (-march=native)

post-patch-NATIVE-off:
	@${REINPLACE_CMD} -e 's| -march=native | |' ${WRKSRC}/apps/linear_algebra/Makefile

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
