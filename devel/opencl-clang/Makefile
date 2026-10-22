PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm17=	17.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules
WWW=		https://github.com/intel/opencl-clang

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unmaintained with no working dependant ports
EXPIRATION=	2026-12-25

LIB_DEPENDS=	libLLVM-${FLAVOR:S/llvm//}.so:devel/${FLAVOR} \
		libLLVMSPIRVLib.so.${FLAVOR:S/llvm//}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${17:L:S/^/llvm/}

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
