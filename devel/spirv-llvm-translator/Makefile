PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm23=	23.1.2
DISTVERSION_llvm22=	22.1.7
DISTVERSION_llvm21=	21.1.12
DISTVERSION_llvm20=	20.1.18
DISTVERSION_llvm19=	19.1.23
DISTVERSION_llvm18=	18.1.28
DISTVERSION_llvm17=	17.0.28
DISTVERSION_llvm16=	16.0.29
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR
WWW=		https://github.com/KhronosGroup/SPIRV-LLVM-Translator

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR}

FLAVORS=	${23 22 21 20 19 18 17 16:L:S/^/llvm/}
CONFLICTS_BUILD=${FLAVOR}-lite

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-LLVM-Translator
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-493-g575b651:headers/projects/SPIRV-Headers
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
PATCHDIR=	${.CURDIR}/files.${FLAVOR}
CXXFLAGS+=	-Wno-enum-constexpr-conversion
CMAKE_ON=	BUILD_SHARED_LIBS LLVM_BUILD_TOOLS LLVM_TOOL_SPIRV_HEADERS_BUILD
CMAKE_ARGS=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}"
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

pre-everything::
	@for f in ${.CURDIR}/files/patch-*; do if [ -e $$f ]; then \
		${ECHO_MSG} "Error: patch-* under \"files\" aren't supported. Move under \"files.<flavor>\" instead."; \
		exit 1; \
	fi; done

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
