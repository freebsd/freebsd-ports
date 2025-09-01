PORTNAME=	lib${GH_PROJECT}
PORTVERSION=	36.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for fast and secure runtime for WebAssembly
WWW=		https://wasmtime.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	build currently failing

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo cmake:indirect cpe
CPE_VENDOR=	bytecodealliance
CPE_PRODUCT=	wasmtime

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bytecodealliance
GH_PROJECT=	wasmtime

CARGO_BUILD_ARGS=	-p wasmtime-c-api
CMAKE_SOURCE_PATH=	${WRKSRC}/crates/c-api

.include "${.CURDIR}/Makefile.cargo"

GH_TUPLE=	WebAssembly:testsuite:f50a662:testsuite/tests/spec_testsuite \
		WebAssembly:wasi-testsuite:2fec29e:wasi_testsuite/tests/wasi_testsuite/wasi-common \
		WebAssembly:wasi-threads:e1893c0:wasi_threads/tests/wasi_testsuite/wasi-threads

post-configure:
	@cd ${CMAKE_SOURCE_PATH} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS}

post-build:
	@cd ${CMAKE_SOURCE_PATH} && ${SETENV} ${MAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/wasmtime
	${INSTALL_DATA} ${WRKSRC}/crates/c-api/include/wasm.h ${STAGEDIR}${PREFIX}/include
	(cd ${WRKSRC}/crates/c-api/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include)
	${RM} ${STAGEDIR}${PREFIX}/include/wasmtime/conf.h.in
	${INSTALL_DATA} ${WRKDIR}/target/release/libwasmtime.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/target/release/libwasmtime.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
