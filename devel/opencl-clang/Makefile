PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm12=	12.0.0
DISTVERSION_llvm11=	11.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/${FLAVOR} \
		libLLVMSPIRVLib.so.${DISTVERSION:R:R}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${12 11:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib
GH_ACCOUNT=	intel
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
_PLIST_FILES=	include/cclang/common_clang.h \
		lib/libopencl-clang.so \
		lib/libopencl-clang.so.${DISTVERSION:R:R}
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}

.if !defined(DEFAULT_MAKESUM)
makesum:
. for f in ${FLAVORS}
	${MAKE} -C${.CURDIR} FLAVOR=$f DEFAULT_MAKESUM=1 ${.TARGET}
. endfor
.endif

.include <bsd.port.mk>
