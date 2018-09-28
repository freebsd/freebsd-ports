# $FreeBSD$

PORTNAME=	rust-bindgen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate Rust bindings from C (and some C++) code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	llvm${MESA_LLVM_VER}>0:devel/llvm${MESA_LLVM_VER}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang-nursery
PLIST_FILES=	bin/bindgen
MESA_LLVM_VER?=	60

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.8.2 \
		bitflags-1.0.3 \
		cc-1.0.6 \
		cexpr-0.2.0 \
		cfg-if-0.1.2 \
		clang-sys-0.23.0 \
		clap-2.24.2 \
		diff-0.1.10 \
		env_logger-0.5.10 \
		glob-0.2.11 \
		humantime-1.1.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.0.0 \
		libc-0.2.39 \
		libloading-0.5.0 \
		log-0.4.1 \
		memchr-2.0.1 \
		nom-1.2.4 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.3.2 \
		quick-error-1.2.1 \
		quote-0.5.1 \
		regex-1.0.0 \
		regex-syntax-0.6.0 \
		shlex-0.1.1 \
		strsim-0.6.0 \
		term_size-0.3.0 \
		termcolor-0.3.4 \
		thread-id-3.1.0 \
		thread_local-0.3.3 \
		ucd-util-0.1.1 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.1.0 \
		unreachable-0.1.1 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		which-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${MESA_LLVM_VER},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs

.include <bsd.port.mk>
