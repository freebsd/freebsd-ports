PORTNAME=	libclc
DISTVERSION=	15.0.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/
DISTNAME=	libclc-${DISTVERSION}.src

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language
WWW=		https://libclc.llvm.org/

LICENSE=	LLVM
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_NAME=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	llvm15>=15.0:devel/llvm15 \
		spirv-llvm-translator-llvm15>0:devel/spirv-llvm-translator@llvm15 \
		libedit>=0:devel/libedit

USES=		cmake compiler:c++11-lib python:build tar:xz
USE_LDCONFIG=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config15

.include <bsd.port.mk>
