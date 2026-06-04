PORTNAME=	wasmer
DISTVERSIONPREFIX=	v
DISTVERSION=	7.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/wasmerio/wasmer/releases/download/${DISTVERSIONFULL}/
DISTFILES=	wasmer-full-source.tar.xz

MAINTAINER=	kjozic@gmail.com
COMMENT=	WebAssembly Runtime supporting WASIX, WASI and Emscripten
WWW=		https://wasmer.io/

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 aarch64
ONLY_FOR_ARCHS_REASON=	only amd64 and aarch64 works so far

BUILD_DEPENDS=	bash>0:shells/bash \
		clang${_LLVM_VERSION}:devel/llvm${_LLVM_VERSION}
LIB_DEPENDS=	libffi.so:devel/libffi \
		libzstd.so:archivers/zstd

USES=		cargo gmake llvm:21 nodejs:build pkgconfig

CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV+=	ENABLE_CRANELIFT=1 \
		ENABLE_LLVM=1 \
		ENABLE_SINGLEPASS=1 \
		ENABLE_V8=0 \
		ENABLE_WAMR=0 \
		ENABLE_WASMI=0 \
		LLVM_SYS_210_PREFIX=${LLVM_PREFIX} \
		RUSTFLAGS="-L ${LOCALBASE}/lib -C linker=clang"

ALL_TARGET=	build-wasmer

CC=		clang${_LLVM_VERSION}
CPP=		clang-cpp${_LLVM_VERSION}
CXX=		clang++${_LLVM_VERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/wasmer

_LLVM_VERSION=	21

pre-configure:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wasmer ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
