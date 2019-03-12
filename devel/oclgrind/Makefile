# Created by: Johannes Dieterich <jmd@freebsd.org>
# $FreeBSD$

PORTNAME=	oclgrind
PORTVERSION=	20190218
PORTREVISION=	0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SPIR interpreter and virtual OpenCL device simulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl \
		llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jrprice
GH_PROJECT=	Oclgrind
GH_TAGNAME=	689daab
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/share/llvm/cmake

.include <bsd.port.mk>
