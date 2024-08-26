PORTNAME=	tree-sitter-graph
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Construct graphs from parsed source code
WWW=		https://docs.rs/tree-sitter-graph/*/tree_sitter_graph/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tree-sitter

CARGO_FEATURES=	cli
CARGO_CRATES=	ahash-0.4.8 \
		aho-corasick-1.1.3 \
		anyhow-1.0.86 \
		atty-0.2.14 \
		autocfg-1.3.0 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		cc-1.0.99 \
		cfg-if-1.0.0 \
		clap-3.2.25 \
		clap_lex-0.2.4 \
		colored-2.1.0 \
		dirs-3.0.2 \
		dirs-sys-0.3.7 \
		env_logger-0.9.3 \
		equivalent-1.0.1 \
		getrandom-0.2.15 \
		hashbrown-0.9.1 \
		hashbrown-0.12.3 \
		hashbrown-0.14.5 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		indexmap-1.9.3 \
		indexmap-2.2.6 \
		indoc-1.0.9 \
		itoa-1.0.11 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		libloading-0.7.4 \
		libredox-0.1.3 \
		log-0.4.21 \
		memchr-2.7.4 \
		once_cell-1.19.0 \
		os_str_bytes-6.6.1 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		redox_users-0.4.5 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		ryu-1.0.18 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_json-1.0.117 \
		smallvec-1.13.2 \
		string-interner-0.12.2 \
		strsim-0.10.0 \
		syn-2.0.67 \
		termcolor-1.4.1 \
		textwrap-0.16.1 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		tree-sitter-0.20.10 \
		tree-sitter-config-0.19.0 \
		tree-sitter-highlight-0.20.1 \
		tree-sitter-loader-0.20.0 \
		tree-sitter-python-0.20.4 \
		tree-sitter-tags-0.20.2 \
		unicode-ident-1.0.12 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
