PORTNAME=	rustc-demangle
DISTVERSION=	0.1.24
PORTREVISION=	11
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

CARGO_CRATES=	arbitrary-1.3.2 \
		cc-1.0.97 \
		compiler_builtins-0.1.111 \
		jobserver-0.1.31 \
		libc-0.2.154 \
		libfuzzer-sys-0.4.7 \
		once_cell-1.19.0 \
		rustc-std-workspace-core-1.0.0

PLIST_FILES=	include/rustc_demangle.h \
		lib/librustc_demangle.a \
		lib/librustc_demangle.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/../../crates/capi/include/rustc_demangle.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/target/release/librustc_demangle.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/target/release/librustc_demangle.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
