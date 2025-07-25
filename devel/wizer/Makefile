PORTNAME=	wizer
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0
PORTREVISION=	3
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebAssembly pre-initializer
WWW=		https://github.com/bytecodealliance/wizer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error when identifying target: "no supported isa found for arch `armv7`"
BROKEN_i386=	compilation fails: unresolved import `wasmtime_asm_macros::asm_sym`

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bytecodealliance

CARGO_CRATES=	addr2line-0.21.0 \
		addr2line-0.24.2 \
		adler-1.0.2 \
		ahash-0.8.11 \
		aho-corasick-1.1.3 \
		allocator-api2-0.2.21 \
		ambient-authority-0.0.2 \
		android_system_properties-0.1.5 \
		anes-0.1.6 \
		ansi_term-0.12.1 \
		anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		anyhow-1.0.95 \
		arbitrary-1.4.1 \
		async-trait-0.1.79 \
		atty-0.2.14 \
		autocfg-1.2.0 \
		backtrace-0.3.71 \
		base64-0.21.7 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bumpalo-3.17.0 \
		byteorder-1.5.0 \
		bytes-1.7.1 \
		cap-fs-ext-3.4.2 \
		cap-net-ext-3.4.2 \
		cap-primitives-3.4.2 \
		cap-rand-3.4.2 \
		cap-std-3.4.2 \
		cap-time-ext-3.4.2 \
		cast-0.3.0 \
		cc-1.0.90 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clap-2.34.0 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_lex-0.7.0 \
		cobs-0.2.3 \
		colorchoice-1.0.0 \
		core-foundation-sys-0.8.7 \
		cpp_demangle-0.4.3 \
		cpufeatures-0.2.12 \
		cranelift-bforest-0.116.1 \
		cranelift-bitset-0.116.1 \
		cranelift-codegen-0.116.1 \
		cranelift-codegen-meta-0.116.1 \
		cranelift-codegen-shared-0.116.1 \
		cranelift-control-0.116.1 \
		cranelift-entity-0.116.1 \
		cranelift-frontend-0.116.1 \
		cranelift-isle-0.116.1 \
		cranelift-native-0.116.1 \
		crc32fast-1.4.0 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.19 \
		crunchy-0.2.2 \
		crypto-common-0.1.6 \
		debugid-0.8.0 \
		derive_arbitrary-1.4.1 \
		digest-0.10.7 \
		directories-next-2.0.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.10.0 \
		embedded-io-0.4.0 \
		encoding_rs-0.8.33 \
		env_filter-0.1.0 \
		env_logger-0.11.3 \
		equivalent-1.0.1 \
		errno-0.3.10 \
		fallible-iterator-0.3.0 \
		fd-lock-4.0.2 \
		flagset-0.4.5 \
		foldhash-0.1.4 \
		form_urlencoded-1.2.1 \
		fs-set-times-0.20.1 \
		futures-0.3.30 \
		futures-channel-0.3.30 \
		futures-core-0.3.30 \
		futures-io-0.3.30 \
		futures-sink-0.3.30 \
		futures-task-0.3.30 \
		futures-util-0.3.30 \
		fxhash-0.2.1 \
		fxprof-processed-profile-0.6.0 \
		generic-array-0.14.7 \
		getrandom-0.2.12 \
		gimli-0.28.1 \
		gimli-0.31.1 \
		half-2.4.0 \
		hashbrown-0.14.3 \
		hashbrown-0.15.2 \
		heck-0.3.3 \
		heck-0.5.0 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.9 \
		humantime-2.1.0 \
		iana-time-zone-0.1.60 \
		iana-time-zone-haiku-0.1.2 \
		id-arena-2.2.1 \
		idna-0.5.0 \
		indexmap-2.7.1 \
		io-extras-0.18.4 \
		io-lifetimes-2.0.3 \
		ipnet-2.9.0 \
		is-terminal-0.4.12 \
		itertools-0.10.5 \
		itertools-0.12.1 \
		itoa-1.0.14 \
		ittapi-0.4.0 \
		ittapi-sys-0.4.0 \
		jobserver-0.1.28 \
		js-sys-0.3.69 \
		lazy_static-1.4.0 \
		leb128-0.2.5 \
		leb128fmt-0.1.0 \
		libc-0.2.169 \
		libfuzzer-sys-0.4.7 \
		libm-0.2.8 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.15 \
		log-0.4.21 \
		mach2-0.4.2 \
		maybe-owned-0.3.4 \
		memchr-2.7.2 \
		memfd-0.6.4 \
		miniz_oxide-0.7.4 \
		mio-1.0.2 \
		num-traits-0.2.18 \
		object-0.32.2 \
		object-0.36.7 \
		once_cell-1.19.0 \
		oorandom-11.1.3 \
		paste-1.0.14 \
		percent-encoding-2.3.1 \
		pin-project-lite-0.2.14 \
		pin-utils-0.1.0 \
		pkg-config-0.3.30 \
		plotters-0.3.5 \
		plotters-backend-0.3.5 \
		plotters-svg-0.3.5 \
		postcard-1.0.8 \
		ppv-lite86-0.2.20 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.93 \
		psm-0.1.21 \
		pulley-interpreter-29.0.1 \
		quote-1.0.35 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_users-0.4.5 \
		regalloc2-0.11.1 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		rustc-demangle-0.1.23 \
		rustc-hash-2.1.1 \
		rustix-0.38.44 \
		ryu-1.0.17 \
		same-file-1.0.6 \
		semver-1.0.22 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.115 \
		serde_spanned-0.6.5 \
		serde_yaml-0.9.34+deprecated \
		sha2-0.10.8 \
		shellexpand-2.1.2 \
		smallvec-1.13.2 \
		socket2-0.5.7 \
		sptr-0.3.2 \
		stable_deref_trait-1.2.0 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.109 \
		syn-2.0.98 \
		system-interface-0.27.2 \
		target-lexicon-0.13.2 \
		termcolor-1.4.1 \
		textwrap-0.11.0 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		tinytemplate-1.2.1 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.39.3 \
		toml-0.8.12 \
		toml_datetime-0.6.5 \
		toml_edit-0.22.9 \
		tracing-0.1.40 \
		tracing-attributes-0.1.27 \
		tracing-core-0.1.32 \
		trait-variant-0.1.2 \
		typenum-1.17.0 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.11 \
		unicode-width-0.2.0 \
		unicode-xid-0.2.4 \
		unsafe-libyaml-0.2.11 \
		url-2.5.2 \
		utf8parse-0.2.1 \
		uuid-1.8.0 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		wasm-encoder-0.202.0 \
		wasm-encoder-0.221.3 \
		wasm-encoder-0.225.0 \
		wasm-smith-0.202.0 \
		wasmparser-0.202.0 \
		wasmparser-0.221.3 \
		wasmparser-0.225.0 \
		wasmprinter-0.202.0 \
		wasmprinter-0.221.3 \
		wasmtime-29.0.1 \
		wasmtime-asm-macros-29.0.1 \
		wasmtime-cache-29.0.1 \
		wasmtime-component-macro-29.0.1 \
		wasmtime-component-util-29.0.1 \
		wasmtime-cranelift-29.0.1 \
		wasmtime-environ-29.0.1 \
		wasmtime-fiber-29.0.1 \
		wasmtime-jit-debug-29.0.1 \
		wasmtime-jit-icache-coherence-29.0.1 \
		wasmtime-math-29.0.1 \
		wasmtime-slab-29.0.1 \
		wasmtime-versioned-export-macros-29.0.1 \
		wasmtime-wasi-29.0.1 \
		wasmtime-winch-29.0.1 \
		wasmtime-wit-bindgen-29.0.1 \
		wast-35.0.2 \
		wast-225.0.0 \
		wat-1.225.0 \
		web-sys-0.3.69 \
		wiggle-29.0.1 \
		wiggle-generate-29.0.1 \
		wiggle-macro-29.0.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winch-codegen-29.0.1 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.5 \
		winx-0.36.3 \
		wit-parser-0.221.3 \
		witx-0.9.1 \
		zerocopy-0.7.32 \
		zerocopy-derive-0.7.32 \
		zstd-0.13.1 \
		zstd-safe-7.1.0 \
		zstd-sys-2.0.10+zstd.1.5.6

CARGO_FEATURES=	env_logger structopt

PLIST_FILES=	bin/${PORTNAME}

# --features="env_logger structopt"

xpost-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
