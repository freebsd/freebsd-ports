# $FreeBSD$

PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.0-1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/llvm${DISTVERSION:R:S/.//g}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-LLVM-Translator
CMAKE_ON=	BUILD_SHARED_LIBS
PLIST_FILES=	include/LLVMSPIRVLib/LLVMSPIRVExtensions.inc \
		include/LLVMSPIRVLib/LLVMSPIRVLib.h \
		include/LLVMSPIRVLib/LLVMSPIRVOpts.h \
		lib/libLLVMSPIRVLib.so \
		lib/libLLVMSPIRVLib.so.${DISTVERSION:R:R} \
		libdata/pkgconfig/LLVMSPIRVLib.pc

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
