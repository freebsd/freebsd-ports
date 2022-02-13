PORTNAME=	inferno
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.12
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stack trace visualizer, a Rust port of flamegraph

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	jonhoo

CARGO_CRATES=	adler32-1.2.0 \
		ahash-0.7.6 \
		ansi_term-0.12.1 \
		arrayvec-0.4.12 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.9.1 \
		bytemuck-1.7.3 \
		cast-0.2.7 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		clap-3.0.14 \
		clap_derive-3.0.14 \
		crc32fast-1.3.2 \
		criterion-0.3.5 \
		criterion-plot-0.4.4 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.7 \
		crossbeam-utils-0.8.7 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		ctor-0.1.21 \
		dashmap-5.1.0 \
		diff-0.1.12 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.9.0 \
		getrandom-0.2.4 \
		half-1.8.2 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.8.0 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		lazy_static-1.4.0 \
		libc-0.2.117 \
		libflate-1.1.2 \
		libflate_lz77-1.1.0 \
		lock_api-0.4.6 \
		log-0.4.14 \
		maplit-1.0.2 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		oorandom-11.1.3 \
		os_str_bytes-6.0.0 \
		output_vt100-0.1.3 \
		parking_lot-0.12.0 \
		parking_lot_core-0.9.1 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		ppv-lite86-0.2.16 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		pretty_assertions-1.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quick-xml-0.22.0 \
		quote-1.0.15 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rgb-0.8.31 \
		rle-decode-fast-1.0.3 \
		rustc_version-0.4.0 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.5 \
		serde-1.0.136 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		smallvec-1.8.0 \
		str_stack-0.1.0 \
		strsim-0.10.0 \
		syn-1.0.86 \
		termcolor-1.1.2 \
		termtree-0.2.4 \
		testing_logger-0.1.1 \
		textwrap-0.11.0 \
		textwrap-0.14.2 \
		tinytemplate-1.2.1 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.32.0 \
		windows_aarch64_msvc-0.32.0 \
		windows_i686_gnu-0.32.0 \
		windows_i686_msvc-0.32.0 \
		windows_x86_64_gnu-0.32.0 \
		windows_x86_64_msvc-0.32.0
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
