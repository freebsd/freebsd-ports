# Created by: Johannes Dieterich <jmd@freebsd.org>

PORTNAME=	oclgrind
PORTVERSION=	21.10
DISTVERSIONPREFIX=	v
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SPIR interpreter and virtual OpenCL device simulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LLVM_VER=	12
BUILD_DEPENDS=	opencl>=0:devel/opencl \
		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl \
		llvm${LLVM_VER}>=0:devel/llvm${LLVM_VER}

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jrprice
GH_PROJECT=	Oclgrind
USE_LDCONFIG=	yes

CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CFLAGS_riscv64=	-mno-relax

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm/

.include <bsd.port.mk>
