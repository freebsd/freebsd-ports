PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm12=	12.0.0
DISTVERSION_llvm11=	11.0.0
DISTVERSION_llvm10=	10.0.0-1
DISTVERSION_llvm90=	9.0.1
DISTVERSION_llvm80=	8.0.1-1
DISTVERSION_llvm70=	7.0.1
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	${PATCHFILES_${FLAVOR}}
PATCHFILES_llvm90+=	3e753ba0cb0f.patch:-p1 # https://github.com/intel/opencl-clang/pull/96
PATCHFILES_llvm90+=	b28f74f9789f.patch:-p1 # https://github.com/intel/opencl-clang/pull/97
PATCHFILES_llvm80+=	${PATCHFILES_llvm90}
PATCHFILES_llvm70+=	${PATCHFILES_llvm90}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/${FLAVOR} \
		libLLVMSPIRVLib.so.${DISTVERSION:R:R}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${12 11 10 90 80 70:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	intel
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	include/cclang/common_clang.h \
		lib/libopencl-clang.so \
		lib/libopencl-clang.so.${DISTVERSION:R:R}
.if ${FLAVOR:U:Mllvm70}
_PLIST_FILES:=	${_PLIST_FILES:S/libopencl-/libcommon_/}
.endif
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}

.if !defined(DEFAULT_MAKESUM)
makesum:
. for f in ${FLAVORS}
	${MAKE} -C${.CURDIR} FLAVOR=$f DEFAULT_MAKESUM=1 ${.TARGET}
. endfor
.endif

.include <bsd.port.mk>
