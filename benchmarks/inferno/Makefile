# $FreeBSD$

PORTNAME=	inferno
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
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
		ahash-0.4.6 \
		ansi_term-0.11.0 \
		arrayvec-0.4.12 \
		assert_cmd-1.0.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.14 \
		bumpalo-3.4.0 \
		bytemuck-1.4.1 \
		byteorder-1.3.4 \
		cast-0.2.3 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		const-random-0.1.12 \
		const-random-macro-0.1.12 \
		const_fn-0.4.3 \
		crc32fast-1.2.1 \
		criterion-0.3.3 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.4.4 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.0 \
		crossbeam-utils-0.7.2 \
		crossbeam-utils-0.8.0 \
		crunchy-0.2.2 \
		csv-1.1.4 \
		csv-core-0.1.10 \
		ctor-0.1.16 \
		dashmap-3.11.10 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.7.1 \
		getrandom-0.1.15 \
		getrandom-0.2.0 \
		half-1.6.0 \
		hashbrown-0.9.1 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		indexmap-1.6.0 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		js-sys-0.3.45 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		libflate-1.0.3 \
		libflate_lz77-1.0.0 \
		log-0.4.11 \
		maplit-1.0.2 \
		maybe-uninit-2.0.0 \
		memchr-2.3.4 \
		memoffset-0.5.6 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		oorandom-11.1.3 \
		output_vt100-0.1.2 \
		plotters-0.2.15 \
		ppv-lite86-0.2.10 \
		predicates-1.0.5 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.24 \
		quick-xml-0.19.0 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		regex-1.4.2 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.21 \
		rgb-0.8.25 \
		rle-decode-fast-1.0.1 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.117 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		str_stack-0.1.0 \
		strsim-0.8.0 \
		structopt-0.3.20 \
		structopt-derive-0.4.13 \
		syn-1.0.50 \
		testing_logger-0.1.1 \
		textwrap-0.11.0 \
		tiny-keccak-2.0.2 \
		tinytemplate-1.1.0 \
		treeline-0.1.0 \
		unicode-segmentation-1.7.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wait-timeout-0.2.0 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.68 \
		wasm-bindgen-backend-0.2.68 \
		wasm-bindgen-macro-0.2.68 \
		wasm-bindgen-macro-support-0.2.68 \
		wasm-bindgen-shared-0.2.68 \
		web-sys-0.3.45 \
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
