PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	11.0.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/llvm${DISTVERSION:R:R}

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

.include <bsd.port.mk>
