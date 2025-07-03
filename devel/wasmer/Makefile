PORTNAME=	wasmer
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	kjozic@gmail.com
COMMENT=	WebAssembly Runtime supporting WASIX, WASI and Emscripten
WWW=		https://wasmer.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only amd64 works so far (with some issues)

BUILD_DEPENDS=	bash>0:shells/bash \
		clang${_LLVM_VERSION}:devel/llvm${_LLVM_VERSION}
LIB_DEPENDS=	libffi.so:devel/libffi \
		libzstd.so:archivers/zstd

USES=		cargo gmake llvm:18 nodejs:build pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wasmerio

CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV+=	ENABLE_CRANELIFT=1 \
		ENABLE_LLVM=1 \
		ENABLE_SINGLEPASS=1 \
		ENABLE_V8=0 \
		ENABLE_WAMR=0 \
		ENABLE_WASMI=0 \
		LLVM_SYS_180_PREFIX=${LLVM_PREFIX} \
		RUSTFLAGS="-L ${LOCALBASE}/lib"

ALL_TARGET=	build-wasmer

CC=		clang${_LLVM_VERSION}
CPP=		clang-cpp${_LLVM_VERSION}
CXX=		clang++${_LLVM_VERSION}

PLIST_FILES=	bin/wasmer

_LLVM_VERSION=	18

pre-configure:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wasmer ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
