PORTNAME=	cbfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	24
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to format codeblocks inside markdown and org documents
WWW=		https://github.com/lukas-reineke/cbfmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	lukas-reineke

CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-3.2.17 \
		clap_lex-0.2.4 \
		crossbeam-utils-0.8.11 \
		fnv-1.0.7 \
		futures-0.3.23 \
		futures-channel-0.3.23 \
		futures-core-0.3.23 \
		futures-executor-0.3.23 \
		futures-io-0.3.23 \
		futures-macro-0.3.23 \
		futures-sink-0.3.23 \
		futures-task-0.3.23 \
		futures-util-0.3.23 \
		globset-0.4.9 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		ignore-0.4.18 \
		indexmap-1.9.1 \
		lazy_static-1.4.0 \
		libc-0.2.131 \
		log-0.4.17 \
		memchr-2.5.0 \
		num_cpus-1.13.1 \
		once_cell-1.13.0 \
		os_str_bytes-6.3.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		same-file-1.0.6 \
		serde-1.0.143 \
		serde_derive-1.0.143 \
		slab-0.4.7 \
		smawk-0.3.1 \
		strsim-0.10.0 \
		syn-1.0.99 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		thiserror-1.0.32 \
		thiserror-impl-1.0.32 \
		thread_local-1.1.4 \
		tokio-1.20.1 \
		tokio-macros-1.8.0 \
		toml-0.5.9 \
		tree-sitter-0.20.8 \
		tree-sitter-md-0.1.1 \
		tree-sitter-org-1.3.0 \
		tree-sitter-rst-0.1.0 \
		unicode-ident-1.0.3 \
		unicode-linebreak-0.1.2 \
		unicode-width-0.1.9 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
