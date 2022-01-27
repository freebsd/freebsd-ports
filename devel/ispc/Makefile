# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	ispc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel's compiler for high-performance SIMD programming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	only available for these architectures

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		m4:devel/m4
LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_VERSION}

USES=		bison cmake compiler:c++14-lang python:build,test shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes

SHEBANG_FILES=	*.py

CONFIGURE_ENV=	PATH=${LOCALBASE}/llvm${LLVM_VERSION}/bin:${PATH}
CMAKE_OFF=	ISPC_NO_DUMPS ISPC_INCLUDE_EXAMPLES

BINARY_ALIAS=	flex=${LOCALBASE}/bin/flex python=${PYTHON_CMD} m4=${LOCALBASE}/bin/gm4

PLIST_FILES=	bin/ispc \
		bin/check_isa

OPTIONS_DEFINE_amd64=	XE
OPTIONS_DEFAULT_amd64=	XE

XE_DESC=		Enable Intel Xe support
XE_BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_VERSION}/lib/libLLVMGenXIntrinsics.a:devel/vc-intrinsics@llvm${LLVM_VERSION}
XE_LIB_DEPENDS=		libze_loader.so:devel/level-zero \
			libLLVMSPIRVLib.so.${LLVM_VERSION}:devel/spirv-llvm-translator@llvm${LLVM_VERSION}
XE_CMAKE_BOOL=		XE_ENABLED
XE_CMAKE_BOOL_OFF=	ISPCRT_BUILD_TESTS
XE_CMAKE_ON=		-DXE_DEPS_DIR:PATH="${LOCALBASE}/llvm${LLVM_VERSION}" -DISPC_INCLUDE_XE_EXAMPLES=OFF
XE_PLIST_FILES=		include/ispcrt/ispcrt.h \
			include/ispcrt/ispcrt.hpp \
			include/ispcrt/ispcrt.isph \
			lib/cmake/ispcrt-${PORTVERSION}/Finddpcpp_compiler.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/Findlevel_zero.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/interop.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/ispc.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/ispcrtConfig.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/ispcrt_Exports-%%CMAKE_BUILD_TYPE%%.cmake \
			lib/cmake/ispcrt-${PORTVERSION}/ispcrt_Exports.cmake \
			lib/libispcrt.so \
			lib/libispcrt.so.1 \
			lib/libispcrt.so.${PORTVERSION} \
			lib/libispcrt_static.a

#.include <bsd.port.options.mk>
#.if ${LLVM_DEFAULT:M[7891]0} || ${LLVM_DEFAULT:M1[12]} # max(LLVM_DEFAULT,13)
#LLVM_VERSION=	13
#.else
#LLVM_VERSION=	${LLVM_DEFAULT}
#.endif

LLVM_VERSION?=	13

do-test: # some tests fail: https://github.com/ispc/ispc/issues/1868, https://github.com/ispc/ispc/issues/2244
	@cd ${WRKSRC} && ISPC_HOME=${BUILD_WRKSRC}/bin ./run_tests.py

test-check-all: # the upstream claims that some of these checks are broken without using their patched llvm version, hence using llvm-devel
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check-all

run-examples: build
	@[ -f ${LOCALBASE}/lib/libtbb.so ] || ! echo "ERROR run-examples target requires devel/tbb package installed"
.for e in simple sort mandelbrot stencil
	@cd ${WRKSRC}/examples/${e} && \
	${ECHO} "===> Running example ${e}" && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
	./${e}
.endfor

.include <bsd.port.mk>
