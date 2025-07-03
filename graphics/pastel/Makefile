PORTNAME=	pastel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	24
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors
WWW=		https://github.com/sharkdp/pastel

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp
SHEBANG_FILES=	doc/demo-scripts/gradient.sh

CARGO_CRATES=	aho-corasick-0.7.18 \
		approx-0.5.1 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.9.1 \
		cast-0.2.7 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		clap-3.1.18 \
		clap_complete-3.1.4 \
		clap_lex-0.2.0 \
		criterion-0.3.5 \
		criterion-plot-0.4.4 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		getrandom-0.2.6 \
		half-1.8.2 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		indexmap-1.8.1 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.2 \
		js-sys-0.3.57 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		minimal-lexical-0.2.1 \
		nom-7.1.1 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.12.0 \
		oorandom-11.1.3 \
		os_str_bytes-6.1.0 \
		output_vt100-0.1.3 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		ppv-lite86-0.2.16 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.39 \
		quote-1.0.18 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_xoshiro-0.6.0 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		regex-1.5.6 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.26 \
		rustc_version-0.4.0 \
		ryu-1.0.10 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.9 \
		serde-1.0.137 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.137 \
		serde_json-1.0.81 \
		strsim-0.10.0 \
		syn-1.0.95 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.11.0 \
		textwrap-0.15.0 \
		tinytemplate-1.2.1 \
		unicode-ident-1.0.0 \
		unicode-width-0.1.9 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.80 \
		wasm-bindgen-backend-0.2.80 \
		wasm-bindgen-macro-0.2.80 \
		wasm-bindgen-macro-support-0.2.80 \
		wasm-bindgen-shared-0.2.80 \
		web-sys-0.3.57 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}
DOCS=		doc/colorcheck.md doc/colorcheck.png \
		doc/demo-scripts/gradient.sh doc/pastel.gif README.md
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
