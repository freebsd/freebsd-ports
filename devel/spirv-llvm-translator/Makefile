PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm21=	21.1.0
DISTVERSION_llvm20=	20.1.5
DISTVERSION_llvm19=	19.1.10
DISTVERSION_llvm18=	18.1.15
DISTVERSION_llvm17=	17.0.15
DISTVERSION_llvm16=	16.0.15
DISTVERSION_llvm15=	15.0.15
DISTVERSION_llvm14=	14.0.14
DISTVERSION_llvm13=	13.0.3
DISTVERSION_llvm12=	12.0.1
DISTVERSION_llvm11=	11.0.4
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR
WWW=		https://github.com/KhronosGroup/SPIRV-LLVM-Translator

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR}

FLAVORS=	${21 20 19 18 17 16 15 14 13 12 11:L:S/^/llvm/}
CONFLICTS_BUILD=${FLAVOR}-lite

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-LLVM-Translator
.if ${FLAVOR:U:Mllvm1[12]}
# empty
.elif ${FLAVOR:U} == llvm21 || !defined(FLAVOR)
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-431-g9e3836d:headers/projects/SPIRV-Headers
.elif ${FLAVOR:U} == llvm20
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-405-g0e71067:headers/projects/SPIRV-Headers
.else
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-411-gaa6cef1:headers/projects/SPIRV-Headers
.endif
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CXXFLAGS+=	${${FLAVOR:S/llvm//} < 16 && ${COMPILER_TYPE} == clang:?-Wno-enum-constexpr-conversion:}
CMAKE_ON=	BUILD_SHARED_LIBS LLVM_BUILD_TOOLS LLVM_TOOL_SPIRV_HEADERS_BUILD
CMAKE_ARGS=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}"
CMAKE_ARGS+=	${${FLAVOR:S/llvm//}==11:?-DBASE_LLVM_VERSION=11.0:}
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	bin/llvm-spirv \
		include/LLVMSPIRVLib/LLVMSPIRVExtensions.inc \
		include/LLVMSPIRVLib/LLVMSPIRVLib.h \
		include/LLVMSPIRVLib/LLVMSPIRVOpts.h \
		lib/libLLVMSPIRVLib.so \
		lib/libLLVMSPIRVLib.so.${SOVERSION} \
		libdata/pkgconfig/LLVMSPIRVLib.pc
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}
SOVERSION=	${${FLAVOR:S/llvm//}<18:?${DISTVERSION:R:R}:${DISTVERSION:R}}

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
