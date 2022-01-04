PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm13=	13.0.0
DISTVERSION_llvm12=	12.0.0
DISTVERSION_llvm11=	11.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR}

FLAVORS=	${13 12 11:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-LLVM-Translator
GH_TUPLE=	${GH_TUPLE_${FLAVOR}}
GH_TUPLE_llvm13=KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-83-gddf3230:headers/projects/SPIRV-Headers
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CMAKE_ON=	BUILD_SHARED_LIBS LLVM_BUILD_TOOLS LLVM_TOOL_SPIRV_HEADERS_BUILD
CMAKE_ARGS=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	bin/llvm-spirv \
		include/LLVMSPIRVLib/LLVMSPIRVExtensions.inc \
		include/LLVMSPIRVLib/LLVMSPIRVLib.h \
		include/LLVMSPIRVLib/LLVMSPIRVOpts.h \
		lib/libLLVMSPIRVLib.so \
		lib/libLLVMSPIRVLib.so.${DISTVERSION:R:R} \
		libdata/pkgconfig/LLVMSPIRVLib.pc
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s/lib/&data/' \
		${WRKSRC}/CMakeLists.txt

.if !defined(DEFAULT_MAKESUM)
makesum:
. for f in ${FLAVORS}
	${MAKE} -C${.CURDIR} FLAVOR=$f DEFAULT_MAKESUM=1 ${.TARGET}
. endfor
.endif

.include <bsd.port.mk>
