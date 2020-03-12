# $FreeBSD$

PORTNAME=	pastel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	vulcan@wired.sh
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp
SHEBANG_FILES=	doc/demo-scripts/gradient.sh

CARGO_CRATES=	aho-corasick-0.7.8 \
		ansi_term-0.11.0 \
		anyhow-1.0.26 \
		approx-0.3.2 \
		arrayvec-0.4.12 \
		assert_cmd-0.12.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		bstr-0.2.11 \
		bumpalo-3.2.0 \
		byteorder-1.3.4 \
		c2-chacha-0.2.3 \
		cast-0.2.3 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		criterion-0.3.1 \
		criterion-plot-0.4.1 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		difference-2.0.0 \
		doc-comment-0.3.1 \
		either-1.5.3 \
		escargot-0.5.0 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.8 \
		itertools-0.8.2 \
		itoa-0.4.5 \
		js-sys-0.3.35 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lexical-core-0.6.2 \
		libc-0.2.67 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memoffset-0.5.3 \
		nodrop-0.1.14 \
		nom-4.2.3 \
		nom-5.1.1 \
		num-traits-0.2.11 \
		num_cpus-1.12.0 \
		oorandom-11.1.0 \
		output_vt100-0.1.2 \
		plotters-0.2.12 \
		ppv-lite86-0.2.6 \
		predicates-1.0.3 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro2-1.0.9 \
		quote-1.0.2 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xoshiro-0.4.0 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		regex-1.3.4 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.14 \
		rustc_version-0.2.3 \
		ryu-1.0.2 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.48 \
		sourcefile-0.1.4 \
		static_assertions-0.3.4 \
		strsim-0.8.0 \
		syn-1.0.16 \
		term_size-0.3.1 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		tinytemplate-1.0.3 \
		treeline-0.1.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		version_check-0.9.1 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.58 \
		wasm-bindgen-backend-0.2.58 \
		wasm-bindgen-macro-0.2.58 \
		wasm-bindgen-macro-support-0.2.58 \
		wasm-bindgen-shared-0.2.58 \
		wasm-bindgen-webidl-0.2.58 \
		web-sys-0.3.35 \
		weedle-0.10.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
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
