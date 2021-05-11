PORTNAME=	inferno
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stack trace visualizer, a Rust port of flamegraph

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	jonhoo

CARGO_CRATES=	adler32-1.2.0 \
		ahash-0.3.8 \
		ahash-0.6.3 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		arrayvec-0.4.12 \
		assert_cmd-1.0.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.16 \
		bumpalo-3.6.1 \
		bytemuck-1.5.1 \
		byteorder-1.4.3 \
		cast-0.2.5 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		const-random-0.1.13 \
		const-random-macro-0.1.13 \
		crc32fast-1.2.1 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.4 \
		crossbeam-utils-0.8.4 \
		crunchy-0.2.2 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		ctor-0.1.20 \
		dashmap-3.11.10 \
		diff-0.1.12 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.8.3 \
		getrandom-0.2.2 \
		half-1.7.1 \
		hashbrown-0.9.1 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		indexmap-1.6.2 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		js-sys-0.3.50 \
		lazy_static-1.4.0 \
		libc-0.2.94 \
		libflate-1.1.0 \
		libflate_lz77-1.1.0 \
		log-0.4.14 \
		maplit-1.0.2 \
		memchr-2.4.0 \
		memoffset-0.6.3 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.7.2 \
		oorandom-11.1.3 \
		output_vt100-0.1.2 \
		plotters-0.3.0 \
		plotters-backend-0.3.0 \
		plotters-svg-0.3.0 \
		ppv-lite86-0.2.10 \
		predicates-1.0.8 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		pretty_assertions-0.7.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.26 \
		quick-xml-0.20.0 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		regex-1.5.3 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.25 \
		rgb-0.8.27 \
		rle-decode-fast-1.0.1 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.125 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.125 \
		serde_json-1.0.64 \
		str_stack-0.1.0 \
		strsim-0.8.0 \
		structopt-0.3.21 \
		structopt-derive-0.4.14 \
		syn-1.0.72 \
		testing_logger-0.1.1 \
		textwrap-0.11.0 \
		tiny-keccak-2.0.2 \
		tinytemplate-1.2.1 \
		treeline-0.1.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.73 \
		wasm-bindgen-backend-0.2.73 \
		wasm-bindgen-macro-0.2.73 \
		wasm-bindgen-macro-support-0.2.73 \
		wasm-bindgen-shared-0.2.73 \
		web-sys-0.3.50 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

EXECUTABLES=	inferno-collapse-dtrace \
		inferno-collapse-guess \
		inferno-collapse-perf \
		inferno-collapse-sample \
		inferno-collapse-vtune \
		inferno-diff-folded \
		inferno-flamegraph

PLIST_FILES=	${EXECUTABLES:S/inferno-/bin\/&/}

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} ${EXECUTABLES}

.include <bsd.port.mk>
