PORTNAME=	compiler-rt
DISTVERSION?=	0
PORTREVISION?=	0
CATEGORIES=	devel lang
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/ \
		https://${PRE_}releases.llvm.org/${LLVM_RELEASE}/${RCDIR}/
PKGNAMEPREFIX=	wasi-
PKGNAMESUFFIX=	${LLVM_VERSION}
DISTNAME=	llvm-project-${DISTVERSION}.src
DISTFILES=	llvm-project-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Clang builtins library for WebAssembly System Interface
WWW=		https://llvm.org/

LICENSE=	LLVM2
LICENSE_NAME=	Apache License 2.0 with LLVM Exceptions
LICENSE_FILE=	${WRKSRC}/llvm/LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

.if ${DISTVERSION} == 0
IGNORE=		is a meta-port; there is nothing to build
PKGNAMESUFFIX=	-master
.endif

BUILD_DEPENDS=	${WASI_SYSROOT}/include/stdarg.h:devel/wasi-libc

USES=		cmake llvm:${LLVM_SUFFIX} tar:xz

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_SUFFIX=	${LLVM_RELEASE:C/\.[0-9]\.[0-9]$//}
DISTINFO_FILE=	${PORTSDIR}/${LLVM_PORT}/distinfo
NO_ARCH=	yes

CC=		${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VERSION}
WASI_SYSROOT=	${LOCALBASE}/share/wasi-sysroot
TRIPLE=		wasm32-wasi
WITHOUT_CPU_CFLAGS=	yes
# try to sync with https://github.com/WebAssembly/wasi-sdk
# Makefile and wasi-sdk.cmake
CMAKE_SOURCE_PATH=	${WRKSRC}/compiler-rt/lib/builtins
CMAKE_ARGS=	-DCMAKE_AR=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
		-DCMAKE_RANLIB=${LOCALBASE}/bin/llvm-ranlib${LLVM_VERSION} \
		-DCMAKE_C_COMPILER_TARGET=${TRIPLE} \
		-DCMAKE_CXX_COMPILER_TARGET=${TRIPLE} \
		-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
		-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
		-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
		-DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY \
		-DCMAKE_SYSROOT=${WASI_SYSROOT} \
		-DCMAKE_C_COMPILER_WORKS=ON \
		-DCOMPILER_RT_BAREMETAL_BUILD=ON \
		-DCOMPILER_RT_INCLUDE_TESTS=OFF \
		-DCOMPILER_RT_HAS_FPIC_FLAG=ON \
		-DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON \
		-DCOMPILER_RT_OS_DIR=wasi

.include <bsd.port.pre.mk>

.if ${LLVM_VERSION} < 16
CMAKE_ARGS+=	-DLLVM_CONFIG_PATH=${LLVM_CONFIG}
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}
PLIST_FILES=	${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}/lib/wasi/libclang_rt.builtins-wasm32.a
.else
CMAKE_ARGS+=	-DLLVM_CMAKE_DIR=${LLVM_PREFIX}
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}/lib/clang/${LLVM_VERSION}
PLIST_FILES=	${LLVM_PREFIX}/lib/clang/${LLVM_VERSION}/lib/wasi/libclang_rt.builtins-wasm32.a
.endif

.include <bsd.port.post.mk>
