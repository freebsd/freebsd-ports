# Created by: Johannes Dieterich <jmd@freebsd.org>
# $FreeBSD$

PORTNAME=	oclgrind
PORTVERSION=	20190907
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SPIR interpreter and virtual OpenCL device simulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl \
		llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jrprice
GH_PROJECT=	Oclgrind
GH_TAGNAME=	e7c87b0
USE_LDCONFIG=	yes

CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm

.include <bsd.port.options.mk>

.if ${LLVM_DEFAULT:S,-devel,990,} >= 90
LLVM_DEFAULT=	80
.endif

.include <bsd.port.mk>
