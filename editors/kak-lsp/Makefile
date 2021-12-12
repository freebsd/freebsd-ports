PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	11.1.0
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
		ansi_term-0.11.0 \
		arc-swap-1.3.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		boxfnonce-0.1.1 \
		bumpalo-3.7.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-utils-0.8.5 \
		daemonize-0.4.1 \
		dirs-2.0.2 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		enum_primitive-0.1.1 \
		form_urlencoded-1.0.1 \
		futures-0.3.17 \
		futures-channel-0.3.17 \
		futures-core-0.3.17 \
		futures-executor-0.3.17 \
		futures-io-0.3.17 \
		futures-macro-0.3.17 \
		futures-sink-0.3.17 \
		futures-task-0.3.17 \
		futures-util-0.3.17 \
		getopts-0.2.21 \
		getrandom-0.2.3 \
		glob-0.3.0 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indoc-1.0.3 \
		itertools-0.10.1 \
		itoa-0.4.8 \
		js-sys-0.3.54 \
		jsonrpc-core-18.0.0 \
		lazy_static-1.4.0 \
		libc-0.2.101 \
		libflate-1.1.1 \
		libflate_lz77-1.1.0 \
		log-0.4.14 \
		lsp-types-0.91.1 \
		matches-0.1.9 \
		memchr-2.4.1 \
		num-integer-0.1.44 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		once_cell-1.8.0 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.10 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.29 \
		pulldown-cmark-0.8.0 \
		quote-1.0.9 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rle-decode-fast-1.0.1 \
		ropey-1.3.1 \
		rustversion-1.0.5 \
		ryu-1.0.5 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.67 \
		serde_repr-0.1.7 \
		slab-0.4.4 \
		slog-2.7.0 \
		slog-async-2.7.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.8.0 \
		sloggers-2.0.2 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		syn-1.0.76 \
		take_mut-0.2.2 \
		term-0.7.0 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		time-0.1.43 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		trackable-1.2.0 \
		trackable_derive-1.0.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.6 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		unindent-0.1.7 \
		url-2.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.77 \
		wasm-bindgen-backend-0.2.77 \
		wasm-bindgen-macro-0.2.77 \
		wasm-bindgen-macro-support-0.2.77 \
		wasm-bindgen-shared-0.2.77 \
		web-sys-0.3.54 \
		whoami-1.1.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

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
