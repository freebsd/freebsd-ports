# $FreeBSD$

PORTNAME=	bindgen
DISTVERSION=	0.50.0
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
PKGNAMEPREFIX=	rust-
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate Rust bindings from C (and some C++) code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	aho-corasick-0.7.4 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		backtrace-0.3.32 \
		backtrace-sys-0.1.30 \
		bitflags-1.1.0 \
		byteorder-1.3.2 \
		cc-1.0.37 \
		cexpr-0.3.5 \
		cfg-if-0.1.9 \
		clang-sys-0.28.0 \
		clap-2.33.0 \
		diff-0.1.11 \
		env_logger-0.6.2 \
		failure-0.1.5 \
		fxhash-0.2.1 \
		glob-0.2.11 \
		humantime-1.2.0 \
		lazy_static-1.3.0 \
		libc-0.2.58 \
		libloading-0.5.1 \
		log-0.4.6 \
		memchr-2.2.0 \
		nom-4.2.3 \
		numtoa-0.1.0 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.4.30 \
		quick-error-1.2.2 \
		quote-0.6.12 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.7 \
		regex-syntax-0.6.7 \
		rustc-demangle-0.1.15 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		termcolor-1.0.5 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.3 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		which-2.0.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_DEFAULT},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs

.include <bsd.port.mk>
