PORTNAME=	spirv-llvm-translator
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm12=	12.0.0
DISTVERSION_llvm11=	11.0.0
DISTVERSION_llvm10=	10.0.0
DISTVERSION_llvm90=	9.0.1-1
DISTVERSION_llvm80=	8.0.1-3
DISTVERSION_llvm70=	7.0.1-1
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bi-directional translation between SPIR-V and LLVM IR

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/${FLAVOR}

FLAVORS=	${12 11 10 90 80 70:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-LLVM-Translator
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CMAKE_ON=	BUILD_SHARED_LIBS LLVM_BUILD_TOOLS
CMAKE_ARGS=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	bin/llvm-spirv \
		include/LLVMSPIRVLib/LLVMSPIRVExtensions.inc \
		include/LLVMSPIRVLib/LLVMSPIRVLib.h \
		include/LLVMSPIRVLib/LLVMSPIRVOpts.h \
		lib/libLLVMSPIRVLib.so \
		lib/libLLVMSPIRVLib.so.${DISTVERSION:R:R} \
		libdata/pkgconfig/LLVMSPIRVLib.pc
.if ${FLAVOR:U:Mllvm[78]0}
_PLIST_FILES:=	${_PLIST_FILES:N*Extensions*}
.endif
.if ${FLAVOR:U:Mllvm70}
_PLIST_FILES:=	${_PLIST_FILES:N*Opts*}
.endif
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
