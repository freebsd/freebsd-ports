PORTNAME=	intel-graphics-compiler
DISTVERSIONPREFIX=	igc-
DISTVERSION=	1.0.10395
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	aa7df33aebe0.patch:-p1 # https://github.com/intel/intel-graphics-compiler/pull/210
PATCHFILES+=	35c947c2631e.patch:-p1 # https://github.com/intel/intel-graphics-compiler/issues/142

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Graphics Compiler for OpenCL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

BUILD_DEPENDS=	vc-intrinsics-${FLAVOR}>=s20210730:devel/vc-intrinsics@${FLAVOR}
LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR} \
		libopencl-clang.so.${FLAVOR:S/llvm//}:devel/opencl-clang@${FLAVOR} \
		libLLVMSPIRVLib.so.${FLAVOR:S/llvm//}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${12 11:L:S/^/llvm/}

CONFLICTS_INSTALL=	${PORTNAME}-llvm*

USES=		bison cmake compiler:c++17-lang python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-123-g814e728:headers/../SPIRV-Headers \
		KhronosGroup:SPIRV-Tools:v2021.4:tools/../SPIRV-Tools
CMAKE_ARGS=	-DCMAKE_PREFIX_PATH:PATH="${LOCALBASE}/${FLAVOR}" \
		-DIGC_OPTION__LLVM_PREFERRED_VERSION:STRING="${FLAVOR:S/llvm//}" \
		-DIGC_OPTION__VC_INTRINSICS_MODE:STRING=Prebuilds
CFLAGS+=	-Wno-macro-redefined # __fastcall
PLIST_SUB=	ARCH_SUFX=${ARCH:S/i386/32/:S/amd//:S/x86_//}

post-patch:
# lang/python* don't install unsuffixed symlinks
	@${REINPLACE_CMD} -i .python \
		-e '/EXECUTABLE/s/"python"/"${PYTHON_CMD:T}"/' \
		-e '/IGC_PYTHON/s/"python"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/IGC/CMakeLists.txt \
		${WRKSRC}/IGC/BiFModule/linux/CMakeLists.txt
# No need to abort on every benign warning enabled by default
# Disable debug symbols unless WITH_DEBUG passed via CXXFLAGS
	@${REINPLACE_CMD} -e 's/"-Werror"//; /-Werror/d' \
		-e 's/"-g"//' \
		${WRKSRC}/IGC/CMakeLists.txt
# Search LLVMSPIRVLib.pc where devel/spirv-llvm-translator installs
	@${REINPLACE_CMD} -e '/pkgconfig/s,$${_libdir},&/../libdata,' \
		${WRKSRC}/IGC/cmake/modules/FindSPIRVLLVMTranslator.cmake

.include <bsd.port.mk>
