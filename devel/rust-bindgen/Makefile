# $FreeBSD$

PORTNAME=	rust-bindgen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.48.1
CATEGORIES=	devel

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate Rust bindings from C (and some C++) code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
PLIST_FILES=	bin/bindgen

CARGO_CRATES=	aho-corasick-0.6.8 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		backtrace-0.3.11 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		byteorder-1.2.7 \
		cc-1.0.25 \
		cexpr-0.3.3 \
		cfg-if-0.1.5 \
		clang-sys-0.26.4 \
		clap-2.32.0 \
		diff-0.1.11 \
		env_logger-0.6.0 \
		failure-0.1.5 \
		glob-0.2.11 \
		hashbrown-0.1.7 \
		humantime-1.1.1 \
		lazy_static-1.1.0 \
		libc-0.2.49 \
		libloading-0.5.0 \
		log-0.4.5 \
		memchr-2.1.0 \
		nom-4.0.0 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.4.19 \
		quick-error-1.2.2 \
		quote-0.6.8 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.5 \
		regex-syntax-0.6.2 \
		rustc-demangle-0.1.13 \
		scopeguard-0.3.3 \
		shlex-0.1.1 \
		strsim-0.7.0 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.1 \
		vec_map-0.8.1 \
		version_check-0.1.4 \
		which-2.0.1 \
		winapi-0.3.5 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_DEFAULT},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs

.include <bsd.port.mk>
