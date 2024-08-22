PORTNAME=	libclc
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm18=	18.1.8
DISTVERSION_llvm17=	17.0.6
DISTVERSION_llvm16=	16.0.6
DISTVERSION_llvm15=	15.0.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/
DISTNAME=	libclc-${DISTVERSION}.src
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language
WWW=		https://libclc.llvm.org/

LICENSE=	LLVM
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_NAME=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	spirv-llvm-translator-${FLAVOR}>0:devel/spirv-llvm-translator@${FLAVOR} \
		libedit>=0:devel/libedit

FLAVORS=	${15 16 17 18:L:S/^/llvm/}

USES=		cmake compiler:c++11-lib llvm:${FLAVOR:S/llvm//},build python:build tar:xz
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib

BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ARGS+=	-DLLVM_DIR:PATH="${LOCALBASE}/${FLAVOR}" \
		-DCMAKE_PREFIX_PATH="${LOCALBASE}/${FLAVOR}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}
DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""
PLIST_SUB+=	LLVM_VERSION=${FLAVOR}

.include <bsd.port.post.mk>

