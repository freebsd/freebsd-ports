PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm16=	16.0.0
DISTVERSION_llvm15=	15.0.0
DISTVERSION_llvm14=	14.0.0
DISTVERSION_llvm13=	13.0.0
DISTVERSION_llvm12=	12.0.0
DISTVERSION_llvm11=	11.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
.if !defined(FLAVOR) || ${FLAVOR} == llvm16
PATCHFILES+=	529a9188114b.patch:-p1 # https://github.com/intel/opencl-clang/pull/415
PATCHFILES+=	9f50367661bb.patch:-p1 # https://github.com/intel/opencl-clang/pull/419
PATCHFILES+=	5491ffa3fde5.patch:-p1 # https://github.com/intel/opencl-clang/pull/416
PATCHFILES+=	cb864cde32c2.patch:-p1 # https://github.com/intel/opencl-clang/issues/422
.endif

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules
WWW=		https://github.com/intel/opencl-clang

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR} \
		libLLVMSPIRVLib.so.${FLAVOR:S/llvm//}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${16 15 14 13 12 11:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	intel
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CMAKE_ARGS=	-DCMAKE_PREFIX_PATH:PATH="${LOCALBASE}/${FLAVOR}" \
		-DPREFERRED_LLVM_VERSION:STRING="${FLAVOR:S/llvm//}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
.if defined(FLAVOR) && ${FLAVOR:S/llvm//} < 16
_PLIST_FILES=	include/cclang/common_clang.h
.else
_PLIST_FILES=	include/cclang/module.modulemap \
		include/cclang/opencl-c-base.h \
		include/cclang/opencl-c.h \
		include/cclang/opencl_clang.h
.endif
_PLIST_FILES+=	lib/libopencl-clang.so \
		lib/libopencl-clang.so.${DISTVERSION:R:R}
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}

.if !defined(DEFAULT_MAKESUM)
makesum:
. for f in ${FLAVORS}
	${MAKE} -C${.CURDIR} FLAVOR=$f DEFAULT_MAKESUM=1 ${.TARGET}
. endfor
.endif

.include <bsd.port.mk>
