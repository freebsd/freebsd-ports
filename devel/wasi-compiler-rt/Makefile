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

USES=		cmake tar:xz

.if ${DISTVERSION} == 0
IGNORE=		is a meta-port; there is nothing to build
PKGNAMESUFFIX=	-master
.else
BUILD_DEPENDS=	${WASI_SYSROOT}/include/stdarg.h:devel/wasi-libc@${LLVM_VERSION}
USES+=		llvm:${LLVM_SUFFIX}
.endif

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_SUFFIX=	${LLVM_RELEASE:C/\.[0-9]\.[0-9]$//}
DISTINFO_FILE=	${PORTSDIR}/${LLVM_PORT}/distinfo
NO_ARCH=	yes

WASI_SYSROOT=	${LOCALBASE}/share/wasi-sysroot
TRIPLE=		wasm32-wasi
WITHOUT_CPU_CFLAGS=	yes
# try to sync with https://github.com/WebAssembly/wasi-sdk
# wasi-sdk.cmake and cmake/wasi-sdk-sysroot.cmake
CMAKE_SOURCE_PATH=	${WRKSRC}/compiler-rt/lib/builtins
CMAKE_ARGS=	-DCMAKE_SYSTEM_NAME=WASI \
		-DCMAKE_SYSTEM_VERSION=1 \
		-DCMAKE_SYSTEM_PROCESSOR=wasm32 \
		-DCMAKE_AR=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
		-DCMAKE_RANLIB=${LOCALBASE}/bin/llvm-ranlib${LLVM_VERSION} \
		-DCMAKE_C_COMPILER_TARGET=${TRIPLE} \
		-DCMAKE_CXX_COMPILER_TARGET=${TRIPLE} \
		-DCMAKE_ASM_COMPILER_TARGET=${TRIPLE} \
		-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
		-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
		-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
		-DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY \
		-DCMAKE_C_COMPILER_WORKS=ON \
		-DCMAKE_CXX_COMPILER_WORKS=ON \
		-DCMAKE_SYSROOT=${WASI_SYSROOT} \
		-DCOMPILER_RT_BAREMETAL_BUILD=ON \
		-DCOMPILER_RT_BUILD_XRAY=OFF \
		-DCOMPILER_RT_INCLUDE_TESTS=OFF \
		-DCOMPILER_RT_HAS_FPIC_FLAG=OFF \
		-DCOMPILER_RT_ENABLE_IOS=OFF \
		-DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON \
		-DCOMPILER_RT_OS_DIR=wasi
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}/lib/clang/${LLVM_VERSION}

PLIST_FILES=	${LLVM_PREFIX}/lib/clang/${LLVM_VERSION}/lib/wasi/libclang_rt.builtins-wasm32.a

.include <bsd.port.mk>
