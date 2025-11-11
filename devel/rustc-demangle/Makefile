PORTNAME=	rustc-demangle
DISTVERSIONPREFIX=	rustc-demangle-v
DISTVERSION=	0.1.26
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Rust symbol demangling
WWW=		https://github.com/rust-lang/rustc-demangle

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../../LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/../../LICENSE-MIT

USES=		cargo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang

WRKSRC_SUBDIR=	crates/capi

CARGO_CRATES=	arbitrary-1.4.2 \
		cc-1.2.45 \
		cfg-if-1.0.4 \
		find-msvc-tools-0.1.4 \
		getrandom-0.3.4 \
		jobserver-0.1.34 \
		libc-0.2.177 \
		libfuzzer-sys-0.4.10 \
		r-efi-5.3.0 \
		rustc-std-workspace-core-1.0.1 \
		shlex-1.3.0 \
		wasip2-1.0.1+wasi-0.2.4 \
		wit-bindgen-0.46.0

PLIST_FILES=	include/rustc_demangle.h \
		lib/librustc_demangle.a \
		lib/librustc_demangle.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/../../crates/capi/include/rustc_demangle.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/target/release/librustc_demangle.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/target/release/librustc_demangle.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
