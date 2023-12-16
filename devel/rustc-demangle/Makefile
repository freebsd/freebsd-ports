PORTNAME=	rustc-demangle
DISTVERSION=	0.1.23
PORTREVISION=	4
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

CARGO_CRATES=	arbitrary-1.3.0 \
		cc-1.0.79 \
		compiler_builtins-0.1.93 \
		jobserver-0.1.26 \
		libc-0.2.146 \
		libfuzzer-sys-0.4.6 \
		once_cell-1.18.0 \
		rustc-std-workspace-core-1.0.0

PLIST_FILES=	include/rustc_demangle.h \
		lib/librustc_demangle.a \
		lib/librustc_demangle.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/../../crates/capi/include/rustc_demangle.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/target/*-freebsd/release/librustc_demangle.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/target/*-freebsd/release/librustc_demangle.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
