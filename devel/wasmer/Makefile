PORTNAME=	wasmer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
CATEGORIES=	devel

MAINTAINER=	kjozic@gmail.com
COMMENT=	WebAssembly Runtime supporting WASIX, WASI and Emscripten
WWW=		https://wasmer.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 riscv64
ONLY_FOR_ARCHS_REASON= only aarch64, amd64 and riscv64 are supported so far
BROKEN_aarch64=	needs fix for mcontext_t in lib/vm/src/trap/traphandlers.rs
BROKEN_riscv64=	build issues

BUILD_DEPENDS=	bash>0:shells/bash

USES=		cargo gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wasmerio

CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV+=	ENABLE_SINGLEPASS=0
ALL_TARGET=	build-wasmer

PLIST_FILES=	bin/wasmer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wasmer ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
