PORTNAME=	pastel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp
SHEBANG_FILES=	doc/demo-scripts/gradient.sh

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		approx-0.3.2 \
		arrayvec-0.5.2 \
		assert_cmd-0.12.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.16 \
		bumpalo-3.7.0 \
		cast-0.2.7 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		escargot-0.5.2 \
		getrandom-0.1.16 \
		half-1.7.1 \
		hermit-abi-0.1.19 \
		itertools-0.9.0 \
		itertools-0.10.1 \
		itoa-0.4.7 \
		js-sys-0.3.51 \
		lazy_static-1.4.0 \
		lexical-core-0.7.6 \
		libc-0.2.97 \
		log-0.4.14 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		nom-5.1.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.8.0 \
		oorandom-11.1.3 \
		output_vt100-0.1.2 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		ppv-lite86-0.2.10 \
		predicates-1.0.8 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xoshiro-0.4.0 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rustc_version-0.4.0 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.3 \
		serde-1.0.126 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		syn-1.0.73 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		tinytemplate-1.2.1 \
		treeline-0.1.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.74 \
		wasm-bindgen-backend-0.2.74 \
		wasm-bindgen-macro-0.2.74 \
		wasm-bindgen-macro-support-0.2.74 \
		wasm-bindgen-shared-0.2.74 \
		web-sys-0.3.51 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}
DOCS=		doc/colorcheck.md doc/colorcheck.png \
		doc/demo-scripts/gradient.sh doc/pastel.gif README.md
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
