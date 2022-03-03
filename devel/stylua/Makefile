PORTNAME=	stylua
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.4
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Opinionated Lua code formatter

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	JohnnyMorganz
GH_PROJECT=	StyLua
CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		anyhow-1.0.53 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		bstr-0.2.16 \
		bumpalo-3.7.0 \
		bytecount-0.5.1 \
		cast-0.2.7 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		console-0.15.0 \
		convert_case-0.4.0 \
		criterion-0.3.5 \
		criterion-plot-0.4.4 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.7 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		derive_more-0.99.16 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		dtoa-0.4.8 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		fnv-1.0.7 \
		full_moon-0.15.1 \
		full_moon_derive-0.10.0 \
		globset-0.4.8 \
		half-1.7.1 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		ignore-0.4.18 \
		indexmap-1.7.0 \
		insta-1.12.0 \
		itertools-0.10.1 \
		itoa-0.4.8 \
		js-sys-0.3.55 \
		lazy_static-1.4.0 \
		libc-0.2.102 \
		linked-hash-map-0.5.4 \
		log-0.4.14 \
		memchr-2.4.1 \
		memoffset-0.6.4 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		oorandom-11.1.3 \
		paste-0.1.18 \
		paste-impl-0.1.18 \
		peg-0.7.0 \
		peg-macros-0.7.0 \
		peg-runtime-0.7.0 \
		pest-2.1.3 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.29 \
		quote-1.0.9 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rustc_version-0.3.3 \
		rustc_version-0.4.0 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-1.0.4 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.136 \
		serde_json-1.0.68 \
		serde_yaml-0.8.21 \
		similar-2.1.0 \
		smol_str-0.1.18 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.76 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		threadpool-1.8.1 \
		tinytemplate-1.2.1 \
		toml-0.5.8 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasm-bindgen-0.2.78 \
		wasm-bindgen-backend-0.2.78 \
		wasm-bindgen-macro-0.2.78 \
		wasm-bindgen-macro-support-0.2.78 \
		wasm-bindgen-shared-0.2.78 \
		web-sys-0.3.55 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5
CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS LUA52 LUAU
OPTIONS_DEFAULT=	LUA52 LUAU

LUA52_DESC=	Build with Lua 5.2 support
LUAU_DESC=	Build with Luau support

LUA52_VARS=	CARGO_FEATURES+=lua52
LUAU_VARS=	CARGO_FEATURES+=luau

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
