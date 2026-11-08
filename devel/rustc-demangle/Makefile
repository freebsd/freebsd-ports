PORTNAME=	rustc-demangle
DISTVERSIONPREFIX=	rustfilt-v
DISTVERSION=	0.2.2
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

CARGO_CRATES=	arbitrary-1.5.0 \
		bitflags-1.3.2 \
		cc-1.10.0 \
		cfg-if-1.0.5 \
		clap-2.34.0 \
		find-msvc-tools-0.1.15 \
		getrandom-0.4.3 \
		jobserver-0.1.35 \
		libc-0.2.191 \
		libfuzzer-sys-0.4.13 \
		r-efi-6.0.0 \
		rustc-demangle-0.1.28 \
		rustc-std-workspace-core-1.0.1 \
		shlex-2.0.1 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-width-0.1.14 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	include/rustc_demangle.h \
		lib/librustc_demangle.a \
		lib/librustc_demangle.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/../../crates/capi/include/rustc_demangle.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/target/release/librustc_demangle.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/target/release/librustc_demangle.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
