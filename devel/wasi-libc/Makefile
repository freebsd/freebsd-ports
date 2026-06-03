PORTNAME=	wasi-libc
DISTVERSIONPREFIX=	wasi-sdk-
DISTVERSION=	32
CATEGORIES=	devel
PKGNAMESUFFIX=	${FLAVOR}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	C standard library for WebAssembly System Interface
WWW=		https://github.com/WebAssembly/wasi-libc

LICENSE=	APACHE20 MIT LLVM2
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_LLVM2=	${WRKSRC}/LICENSE-APACHE-LLVM
LICENSE_NAME_LLVM2=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS_LLVM2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}

FLAVORS=	19 20 21 22 18 17
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake llvm:${FLAVOR}
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	WebAssembly:WASI:59cbe14:wasi/tools/wasi-headers/WASI
NO_ARCH=	yes
PLIST=		${PKGDIR}/pkg-plist${LLVM_VERSION}
PLIST_SUB=	TRIPLE=${TRIPLE}
CONFLICTS_INSTALL=	wasi-libc[0-9]*
WITHOUT_CPU_CFLAGS=	yes

# NOTE: matches the https://github.com/WebAssembly/wasi-sdk
WASI_SYSROOT=	${PREFIX}/share/wasi-sysroot
TRIPLE=		wasm32-wasip1

CMAKE_INSTALL_PREFIX=	${WASI_SYSROOT}
CMAKE_ARGS=	-DCMAKE_AR=llvm-ar${LLVM_VERSION} \
		-DCMAKE_NM=llvm-nm${LLVM_VERSION} \
		-DCMAKE_RANLIB=llvm-ranlib${LLVM_VERSION} \
		-DTARGET_TRIPLE=${TRIPLE} \
		-DBUILTINS_LIB=${LLVM_PREFIX:S|${PREFIX}|${LOCALBASE}|}/lib/clang/${LLVM_VERSION}/lib/${TRIPLE:S|-|-unknown-|}/libclang_rt.builtins.a \
		-DBUILD_SHARED=OFF

.include <bsd.port.mk>
