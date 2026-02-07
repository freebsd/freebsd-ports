PORTNAME=	halide
DISTVERSIONPREFIX=	v
DISTVERSION=	18.0.0
PORTEPOCH=	1
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for fast and portable data-parallel computation
WWW=		https://halide-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to build: unhandled exception: Error: No arm support for this OS, see https://github.com/halide/Halide/issues/6972
BROKEN_armv7=		fails to compile: no error message, except that the header generation command failed
BROKEN_i386=		fails to compile: error: _Float16 is not supported on this target
BROKEN_riscv64=		fails to build: /usr/include/c++/v1/__config:1141:6: No thread API

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION} # because halide expects LLVMConfig.cmake
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

USES=		cmake:testing llvm:${LLVM_VERSION},lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	Halide

LLVM_VERSION=	17

CMAKE_ARGS=	-DHalide_REQUIRE_LLVM_VERSION=${LLVM_VERSION}
CMAKE_ON=	LLVM_USE_SHARED_LLVM_LIBRARY HALIDE_SHARED_LIBRARY \
		Halide_SHARED_LLVM
CMAKE_OFF=	WITH_PYTHON_BINDINGS WITH_APPS WITH_TUTORIALS WITH_DOCS WITH_TESTS # APPS are demos
CMAKE_OFF+=	Halide_WITH_INTROSPECTION # missing program_invocation_name variable, see https://github.com/halide/Halide/issues/6945#issuecomment-1217146679
CMAKE_OFF+=	WITH_WABT # fetches wabt (when www/wabt is available)
CMAKE_OFF+=	WITH_SERIALIZATION # fetches flatbuffers (unless FLATBUFFERS_USE_FETCHCONTENT=OFF)
CMAKE_TESTING_ON=	WITH_TESTS

OPTIONS_DEFINE=	NATIVE
OPTIONS_DEFAULT=

NATIVE_DESC=	Build with native optimizations (-march=native)

PORTSCOUT=	limit:^.*\. # prevent release_NNNN_NN_NN

post-patch-NATIVE-off:
	@${REINPLACE_CMD} -e 's| -march=native | |' ${WRKSRC}/apps/linear_algebra/Makefile

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

# tests fail to compile, see https://github.com/halide/Halide/issues/8236
# Vulkan support isn't enabled for some reason: Configure finds Vulkan but target.has_gpu_feature() returns false, see https://github.com/halide/Halide/issues/8375

.include <bsd.port.mk>
