PORTNAME=	compiler-rt
DISTVERSION=	12.0.1
CATEGORIES=	devel lang
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/ \
		https://${PRE_}releases.llvm.org/${LLVM_RELEASE}/${RCDIR}
PKGNAMEPREFIX=	wasi-
PKGNAMESUFFIX=	${LLVM_SUFFIX}
DISTNAME=	llvm-project-${DISTVERSION}.src
DISTFILES=	llvm-project-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Clang builtins library for WebAssembly System Interface

LICENSE=	LLVM2
LICENSE_FILE=	${WRKSRC}/llvm/LICENSE.TXT
LICENSE_NAME=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	this ports exists solely for building Firefox 95+ in 2021Q4
EXPIRATION_DATE=2022-01-15

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_SUFFIX=	${LLVM_RELEASE:C/\.[0-9]\.[0-9]$//}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}

WASI_SYSROOT=	${LOCALBASE}/share/wasi-sysroot

BUILD_DEPENDS=	${WASI_SYSROOT}/include/stdarg.h:devel/wasi-libc \
		clang${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX}

USES=		cmake tar:xz
NO_ARCH=	yes

PLIST_FILES=	llvm${LLVM_SUFFIX}/lib/clang/${LLVM_RELEASE}/lib/wasi/libclang_rt.builtins-wasm32.a

CC=		${LOCALBASE}/bin/clang${LLVM_SUFFIX}
CXX=		${LOCALBASE}/bin/clang++${LLVM_SUFFIX}

CMAKE_SOURCE_PATH=	${WRKSRC}/compiler-rt/lib/builtins
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}
CMAKE_ARGS=	-DCMAKE_C_COMPILER_WORKS=1 \
		-DCMAKE_SYSROOT=${WASI_SYSROOT} \
		-DLLVM_CONFIG_PATH=${LOCALBASE}/bin/llvm-config${LLVM_SUFFIX} \
		-DCOMPILER_RT_OS_DIR=wasi \
		-DCOMPILER_RT_BAREMETAL_BUILD=TRUE \
		-DCOMPILER_RT_DEFAULT_TARGET_TRIPLE=wasm32-wasi \
		-DCOMPILER_RT_EXCLUDE_ATOMIC_BUILTIN=TRUE

post-build:
	${LOCALBASE}/bin/llvm-ranlib${LLVM_SUFFIX} ${CONFIGURE_WRKSRC}/lib/wasi/*.a

.include <bsd.port.mk>
