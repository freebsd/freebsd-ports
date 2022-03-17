PORTNAME=	vc-intrinsics
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	LLVM intrinsics for SIMD on GPU

LICENSE=	MIT

FLAVORS=	${13 12 11:L:S/^/llvm/}

BUILD_DEPENDS=	${FLAVOR}>0:devel/${FLAVOR}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	intel
CMAKE_ARGS=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	include/llvm/GenXIntrinsics/GenXIntrOpts.h \
		include/llvm/GenXIntrinsics/GenXIntrinsicDescription.gen \
		include/llvm/GenXIntrinsics/GenXIntrinsicInst.h \
		include/llvm/GenXIntrinsics/GenXIntrinsics.h \
		include/llvm/GenXIntrinsics/GenXMetadata.h \
		include/llvm/GenXIntrinsics/GenXSPIRVReaderAdaptor.h \
		include/llvm/GenXIntrinsics/GenXSPIRVWriterAdaptor.h \
		include/llvm/GenXIntrinsics/GenXSimdCFLowering.h \
		include/llvm/GenXIntrinsics/GenXVersion.h \
		lib/cmake/LLVMGenXIntrinsics/LLVMGenXIntrinsicsConfig-%%CMAKE_BUILD_TYPE%%.cmake \
		lib/cmake/LLVMGenXIntrinsics/LLVMGenXIntrinsicsConfig.cmake \
		lib/cmake/VCIntrinsics${FLAVOR:S/llvm//}/VCIntrinsics${FLAVOR:S/llvm//}Config-%%CMAKE_BUILD_TYPE%%.cmake \
		lib/cmake/VCIntrinsics${FLAVOR:S/llvm//}/VCIntrinsics${FLAVOR:S/llvm//}Config.cmake \
		lib/libLLVMGenXIntrinsics.a
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}

.include <bsd.port.mk>
