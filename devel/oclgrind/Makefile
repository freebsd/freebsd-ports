# Created by: Johannes Dieterich <jmd@freebsd.org>
# $FreeBSD$

PORTNAME=	oclgrind
PORTVERSION=	20180101
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SPIR interpreter and virtual OpenCL device simulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl \
		llvm-config50:devel/llvm50
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jrprice
GH_PROJECT=	Oclgrind
GH_TAGNAME=	e99899d
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm50/share/llvm/cmake

.include <bsd.port.mk>
