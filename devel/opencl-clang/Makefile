# $FreeBSD$

PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	29a1f0d9e4e2.patch:-p1 # unbreak on non-x86
PATCHFILES+=	b25df8a90fec.patch:-p1 # don't require Git

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/llvm${DISTVERSION:R:S/.//g} \
		libLLVMSPIRVLib.so.${DISTVERSION:R:R}:devel/spirv-llvm-translator

USES=		cmake compiler:c++11-lib localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_OFF=	LLVMSPIRV_INCLUDED_IN_LLVM
CMAKE_ARGS=	-DSPIRV_TRANSLATOR_DIR:PATH="${PREFIX}/lib"
PLIST_FILES=	include/cclang/common_clang.h \
		lib/libopencl-clang.so \
		lib/libopencl-clang.so.${DISTVERSION:R:R}

pre-configure:
# XXX devel/llvm* only includes DetermineGCCCompatible if OPENMP is enabled
	@if [ ! -e ${LOCALBASE}/llvm${DISTVERSION:R:S/.//g}/lib/cmake/llvm/DetermineGCCCompatible.cmake ]; then \
		${MKDIR} ${WRKSRC}/cmake; \
		${SED} 's/.*DetermineGCCCompatible.*/set(LLVM_COMPILER_IS_GCC_COMPATIBLE ON)/' \
			${LOCALBASE}/llvm${DISTVERSION:R:S/.//g}/lib/cmake/llvm/AddLLVM.cmake \
			>${WRKSRC}/cmake/AddLLVM.cmake; \
		${REINPLACE_CMD} $$'1a\\\nlist(APPEND CMAKE_MODULE_PATH $${CMAKE_SOURCE_DIR}/cmake)\n' \
			${WRKSRC}/CMakeLists.txt; \
	fi

.include <bsd.port.mk>
