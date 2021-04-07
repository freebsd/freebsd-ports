PORTNAME=	intel-graphics-compiler
DISTVERSIONPREFIX=	igc-
DISTVERSION=	1.0.7041
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Graphics Compiler for OpenCL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libopencl-clang.so:devel/opencl-clang

USES=		bison cmake compiler:c++17-lang python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
GH_TUPLE=	intel:vc-intrinsics:069ced1:vcintrin/../vc-intrinsics
CMAKE_OFF=	INSTALL_SPIRVDLL
CFLAGS+=	-Wno-macro-redefined # __fastcall
PLIST_SUB=	ARCH_SUFX=${ARCH:S/i386/32/:S/amd//:S/x86_//}

post-patch:
# lang/python* don't install unsuffixed symlinks
	@${REINPLACE_CMD} -i .python \
		-e '/EXECUTABLE/s/"python"/"${PYTHON_CMD:T}"/' \
		-e '/IGC_PYTHON/s/"python"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/IGC/CMakeLists.txt \
		${WRKSRC}/IGC/BiFModule/linux/CMakeLists.txt
# devel/llvm* have different naming from upstream under PATH
	@${REINPLACE_CMD} -e '/clang-\$$/s//clang$$/' \
		${WRKSRC}/IGC/cmake/igc_find_opencl_clang.cmake
# No need to abort on every benign warning enabled by default
	@${REINPLACE_CMD} -e 's/"-Werror"//; /-Werror/d' \
		${WRKSRC}/IGC/CMakeLists.txt

pre-configure:
# Only one libLLVM can be loaded, so use the same version as devel/opencl-clang
	@for f in ${LOCALBASE}/lib/libopencl-clang.so.*; do \
		${REINPLACE_CMD} "/set.*LLVM.*VERSION/s/\".*\"/\"$${f##*so.}\"/" \
			${WRKSRC}/external/llvm/llvm_preferred_version.cmake; \
	done

.include <bsd.port.mk>
