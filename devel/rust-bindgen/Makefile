# $FreeBSD$

PORTNAME=	bindgen
DISTVERSION=	0.53.2
PORTREVISION=	1
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

CARGO_CRATES=	aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		atty-0.2.13 \
		bitflags-1.2.0 \
		byteorder-1.3.2 \
		cc-1.0.45 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		clang-sys-0.29.0 \
		clap-2.33.0 \
		diff-0.1.11 \
		env_logger-0.7.0 \
		glob-0.3.0 \
		humantime-1.3.0 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.66 \
		libloading-0.5.2 \
		log-0.4.8 \
		memchr-2.2.1 \
		nom-5.1.1 \
		peeking_take_while-0.1.2 \
		proc-macro2-1.0.4 \
		quick-error-1.2.2 \
		quote-1.0.2 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		rustc-hash-1.0.1 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		unicode-width-0.1.6 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		which-3.0.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_DEFAULT},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs

.include <bsd.port.mk>
