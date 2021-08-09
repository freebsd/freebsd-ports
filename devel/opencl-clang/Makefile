PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	11.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${DISTVERSION:R:R}.so:devel/llvm${DISTVERSION:R:R} \
		libLLVMSPIRVLib.so.${DISTVERSION:R:R}:devel/spirv-llvm-translator@llvm${DISTVERSION:R:R}

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
PLIST_FILES=	include/cclang/common_clang.h \
		lib/libopencl-clang.so \
		lib/libopencl-clang.so.${DISTVERSION:R:R}

.include <bsd.port.mk>
