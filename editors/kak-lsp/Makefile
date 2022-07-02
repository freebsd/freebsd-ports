PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	12.2.1
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2018.10.27:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ul

CARGO_CRATES=	adler32-1.2.0 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		arc-swap-1.5.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		boxfnonce-0.1.1 \
		bumpalo-3.9.1 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.34.0 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.4 \
		crossbeam-utils-0.8.8 \
		daemonize-0.4.1 \
		diffs-0.4.1 \
		dirs-2.0.2 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		enum_primitive-0.1.1 \
		field-offset-0.3.4 \
		form_urlencoded-1.0.1 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		getopts-0.2.21 \
		getrandom-0.2.6 \
		glob-0.3.0 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indoc-1.0.4 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		jsonrpc-core-18.0.0 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		libflate-1.2.0 \
		libflate_lz77-1.1.0 \
		log-0.4.16 \
		lsp-types-0.92.1 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		num-integer-0.1.44 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		num_threads-0.1.5 \
		once_cell-1.10.0 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.16 \
		proc-macro2-1.0.36 \
		pulldown-cmark-0.8.0 \
		quote-1.0.17 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.12 \
		redox_users-0.4.2 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		rle-decode-fast-1.0.3 \
		ropey-1.4.1 \
		rustc_version-0.3.3 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serde_repr-0.1.7 \
		slab-0.4.5 \
		slog-2.7.0 \
		slog-async-2.7.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.1 \
		slog-term-2.9.0 \
		sloggers-2.1.1 \
		smallvec-1.8.0 \
		str_indices-0.3.2 \
		strsim-0.8.0 \
		syn-1.0.90 \
		take_mut-0.2.2 \
		term-0.7.0 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.4 \
		time-0.1.43 \
		time-0.3.9 \
		time-macros-0.2.4 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		trackable-1.2.0 \
		trackable_derive-1.0.0 \
		ucd-trie-0.1.3 \
		unicase-2.6.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		unindent-0.1.8 \
		url-2.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		whoami-1.2.1 \
		widestring-0.4.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-acl-0.3.0

SUB_FILES=	pkg-message

PLIST_FILES=	bin/kak-lsp \
		"@sample ${ETCDIR}/kak-lsp.toml.sample"
PORTDOCS=	README.asciidoc

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak-lsp
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/kak-lsp.toml ${STAGEDIR}${ETCDIR}/kak-lsp.toml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
