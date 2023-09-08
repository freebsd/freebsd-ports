PORTNAME=	anki
DISTVERSION=	2.1.66
PORTREVISION=	1
# Don't forget to update ${_MY_BUILDHASH} if DISTVERSION changes
CATEGORIES=	games education python
MASTER_SITES=	LOCAL/kai/:yarncache
DISTFILES=	anki-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}:yarncache

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition
WWW=		https://apps.ankiweb.net/

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the provided build system written in Rust (= runner) accepts only 64-bit systems.

BUILD_DEPENDS=	protoc:devel/protobuf \
		rsync:net/rsync \
		yarn:www/yarn \
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy-protobuf>=1.21:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	lame:audio/lame \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=2.0.0:www/py-waitress@${PY_FLAVOR}

# USES=ssl is required for the compilation of the Rust code
USES=		cargo desktop-file-utils ninja nodejs:build pyqt:6 python:3.9+ \
		shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ankitects
# Translation files
GH_TUPLE=	ankitects:anki-core-i18n:7123006:ftlrslib \
		ankitects:anki-desktop-ftl:75af3ed:ftlextra

USE_PYQT=	pyqt6 sip:build webengine

SHEBANG_FILES=	qt/tools/runanki.system.in

CARGO_CRATES=	addr2line-0.20.0 \
		adler-1.0.2 \
		ahash-0.8.3 \
		aho-corasick-0.7.20 \
		aho-corasick-1.0.2 \
		allocator-api2-0.2.15 \
		ammonia-3.3.0 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anes-0.1.6 \
		anstream-0.3.2 \
		anstyle-1.0.1 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-1.0.1 \
		anyhow-1.0.71 \
		apple-bundles-0.17.0 \
		arrayref-0.3.7 \
		arrayvec-0.7.4 \
		assert-json-diff-2.0.2 \
		async-channel-1.8.0 \
		async-compression-0.4.0 \
		async-stream-0.3.5 \
		async-stream-impl-0.3.5 \
		async-trait-0.1.68 \
		autocfg-1.1.0 \
		axum-0.6.18 \
		axum-client-ip-0.4.1 \
		axum-core-0.3.4 \
		axum-macros-0.3.7 \
		backtrace-0.3.68 \
		base64-0.13.1 \
		base64-0.21.2 \
		bitflags-1.3.2 \
		bitflags-2.3.3 \
		blake3-1.4.0 \
		block-buffer-0.10.4 \
		block-padding-0.3.3 \
		bstr-0.2.17 \
		bstr-1.5.0 \
		bumpalo-3.13.0 \
		byteorder-1.4.3 \
		bytes-1.4.0 \
		camino-1.1.4 \
		cast-0.3.0 \
		cbc-0.1.2 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.26 \
		ciborium-0.2.1 \
		ciborium-io-0.2.1 \
		ciborium-ll-0.2.1 \
		cipher-0.4.4 \
		clap-4.3.10 \
		clap_builder-4.3.10 \
		clap_complete-4.3.1 \
		clap_derive-4.3.2 \
		clap_lex-0.5.0 \
		coarsetime-0.1.23 \
		codespan-0.11.1 \
		codespan-reporting-0.11.1 \
		colorchoice-1.0.0 \
		concurrent-queue-2.2.0 \
		constant_time_eq-0.2.6 \
		convert_case-0.6.0 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.4 \
		cpufeatures-0.2.8 \
		crc32fast-1.3.2 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		crypto-common-0.1.6 \
		data-encoding-2.4.0 \
		deadpool-0.9.5 \
		deadpool-runtime-0.1.2 \
		des-0.8.1 \
		difflib-0.4.0 \
		digest-0.10.7 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		displaydoc-0.2.4 \
		doc-comment-0.3.3 \
		duct-0.13.6 \
		dunce-1.0.4 \
		either-1.8.1 \
		elasticlunr-rs-3.0.2 \
		encoding_rs-0.8.32 \
		env_logger-0.10.0 \
		envy-0.4.2 \
		equivalent-1.0.0 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		event-listener-2.5.3 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		fastrand-1.9.0 \
		filetime-0.2.21 \
		find-winsdk-0.2.0 \
		fixedbitset-0.4.2 \
		flate2-1.0.26 \
		fluent-0.16.0 \
		fluent-bundle-0.15.2 \
		fluent-langneg-0.13.0 \
		fluent-syntax-0.11.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.2.0 \
		forwarded-header-value-0.1.1 \
		fs2-0.4.3 \
		fsevent-sys-4.1.0 \
		futf-0.1.5 \
		futures-0.3.28 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-executor-0.3.28 \
		futures-io-0.3.28 \
		futures-lite-1.13.0 \
		futures-macro-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-timer-3.0.2 \
		futures-util-0.3.28 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.1.16 \
		getrandom-0.2.10 \
		gimli-0.27.3 \
		glob-0.3.1 \
		globset-0.4.10 \
		h2-0.3.20 \
		half-1.8.2 \
		handlebars-4.3.7 \
		hashbrown-0.12.3 \
		hashbrown-0.14.0 \
		hashlink-0.8.3 \
		headers-0.3.8 \
		headers-core-0.2.0 \
		heck-0.4.1 \
		hermit-abi-0.3.2 \
		hex-0.4.3 \
		hmac-0.12.1 \
		html5ever-0.26.0 \
		htmlescape-0.3.1 \
		http-0.2.9 \
		http-body-0.4.5 \
		http-range-header-0.3.0 \
		http-types-2.12.0 \
		httparse-1.8.0 \
		httpdate-1.0.2 \
		humantime-2.1.0 \
		hyper-0.14.27 \
		hyper-rustls-0.24.0 \
		hyper-tls-0.5.0 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		id_tree-1.8.0 \
		idna-0.4.0 \
		ignore-0.4.20 \
		indexmap-1.9.3 \
		indexmap-2.0.0 \
		indoc-1.0.9 \
		infer-0.2.3 \
		inflections-1.1.1 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		inout-0.1.3 \
		instant-0.1.12 \
		intl-memoizer-0.5.1 \
		intl_pluralrules-7.0.2 \
		io-lifetimes-1.0.11 \
		ipnet-2.8.0 \
		is-terminal-0.4.8 \
		itertools-0.10.5 \
		itertools-0.11.0 \
		itoa-1.0.6 \
		jobserver-0.1.26 \
		js-sys-0.3.64 \
		junction-1.0.0 \
		kqueue-1.0.7 \
		kqueue-sys-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		libsqlite3-sys-0.26.0 \
		line-wrap-0.1.1 \
		linkify-0.7.0 \
		linux-raw-sys-0.3.8 \
		linux-raw-sys-0.4.3 \
		lock_api-0.4.10 \
		log-0.4.19 \
		lzma-sys-0.1.20 \
		mac-0.1.1 \
		maplit-1.0.2 \
		markup5ever-0.11.0 \
		markup5ever_rcdom-0.2.0 \
		matchers-0.1.0 \
		matches-0.1.10 \
		matchit-0.7.0 \
		mdbook-0.4.31 \
		memchr-2.5.0 \
		memoffset-0.9.0 \
		mime-0.3.17 \
		mime_guess-2.0.4 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.7.1 \
		mio-0.8.8 \
		multer-2.1.0 \
		multimap-0.8.3 \
		native-tls-0.2.11 \
		new_debug_unreachable-1.0.4 \
		nom-7.1.3 \
		nonempty-0.7.0 \
		notify-5.2.0 \
		notify-debouncer-mini-0.2.1 \
		nu-ansi-term-0.46.0 \
		num-format-0.4.4 \
		num-traits-0.2.15 \
		num_cpus-1.16.0 \
		num_enum-0.6.1 \
		num_enum_derive-0.6.1 \
		object-0.31.1 \
		once_cell-1.18.0 \
		oorandom-11.1.3 \
		opener-0.5.2 \
		openssl-0.10.55 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.90 \
		option-ext-0.2.0 \
		os_pipe-1.1.4 \
		overload-0.1.1 \
		p12-0.6.3 \
		parking-2.1.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		pem-1.1.1 \
		percent-encoding-2.3.0 \
		pest-2.7.0 \
		pest_derive-2.7.0 \
		pest_generator-2.7.0 \
		pest_meta-2.7.0 \
		petgraph-0.6.3 \
		phf-0.10.1 \
		phf-0.11.2 \
		phf_codegen-0.10.0 \
		phf_generator-0.10.0 \
		phf_generator-0.11.2 \
		phf_macros-0.11.2 \
		phf_shared-0.10.0 \
		phf_shared-0.11.2 \
		pin-project-1.1.1 \
		pin-project-internal-1.1.1 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.27 \
		plist-1.4.3 \
		plotters-0.3.5 \
		plotters-backend-0.3.5 \
		plotters-svg-0.3.5 \
		ppv-lite86-0.2.17 \
		precomputed-hash-0.1.1 \
		prettyplease-0.1.25 \
		prettyplease-0.2.9 \
		proc-macro-crate-1.3.1 \
		proc-macro-hack-0.5.20+deprecated \
		proc-macro2-1.0.63 \
		prost-0.11.9 \
		prost-build-0.11.9 \
		prost-derive-0.11.9 \
		prost-reflect-0.11.4 \
		prost-types-0.11.9 \
		pulldown-cmark-0.8.0 \
		pulldown-cmark-0.9.3 \
		pyo3-0.19.0 \
		pyo3-build-config-0.19.0 \
		pyo3-ffi-0.19.0 \
		pyo3-macros-0.19.0 \
		pyo3-macros-backend-0.19.0 \
		quick-xml-0.28.2 \
		quote-1.0.29 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.4 \
		rand_hc-0.2.0 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		rc2-0.8.1 \
		rcgen-0.10.0 \
		redox_syscall-0.2.16 \
		redox_syscall-0.3.5 \
		redox_users-0.4.3 \
		regex-1.9.1 \
		regex-automata-0.1.10 \
		regex-automata-0.3.4 \
		regex-syntax-0.6.29 \
		regex-syntax-0.7.4 \
		reqwest-0.11.18 \
		retain_mut-0.1.9 \
		ring-0.16.20 \
		rusqlite-0.29.0 \
		rustc-demangle-0.1.23 \
		rustc-hash-1.1.0 \
		rustix-0.37.21 \
		rustix-0.38.1 \
		rustls-0.21.2 \
		rustls-native-certs-0.6.3 \
		rustls-pemfile-1.0.3 \
		rustls-webpki-0.100.1 \
		rustversion-1.0.12 \
		ryu-1.0.13 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		schannel-0.1.21 \
		scoped-tls-1.0.1 \
		scopeguard-1.1.0 \
		sct-0.7.0 \
		security-framework-2.9.1 \
		security-framework-sys-2.9.0 \
		self_cell-0.10.2 \
		semver-1.0.17 \
		serde-1.0.164 \
		serde-aux-4.2.0 \
		serde_derive-1.0.164 \
		serde_json-1.0.99 \
		serde_path_to_error-0.1.11 \
		serde_qs-0.8.5 \
		serde_repr-0.1.12 \
		serde_tuple-0.5.0 \
		serde_tuple_macros-0.5.0 \
		serde_urlencoded-0.7.1 \
		sha1-0.10.5 \
		sha2-0.10.7 \
		sharded-slab-0.1.4 \
		shared_child-1.0.0 \
		shlex-1.1.0 \
		signal-hook-registry-1.4.1 \
		simple-file-manifest-0.11.0 \
		siphasher-0.3.10 \
		slab-0.4.8 \
		smallvec-1.10.0 \
		snafu-0.7.4 \
		snafu-derive-0.7.4 \
		snowflake-1.3.0 \
		socket2-0.4.9 \
		spin-0.5.2 \
		spin-0.9.8 \
		string_cache-0.8.7 \
		string_cache_codegen-0.5.2 \
		strsim-0.10.0 \
		strum-0.25.0 \
		strum_macros-0.25.0 \
		subtle-2.5.0 \
		syn-1.0.109 \
		syn-2.0.22 \
		sync_wrapper-0.1.2 \
		tar-0.4.38 \
		target-lexicon-0.12.8 \
		tempfile-3.6.0 \
		tendril-0.4.3 \
		termcolor-1.2.0 \
		terminal_size-0.2.6 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		thread_local-1.1.7 \
		time-0.3.22 \
		time-core-0.1.1 \
		time-macros-0.2.9 \
		tinystr-0.7.1 \
		tinytemplate-1.2.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.29.1 \
		tokio-macros-2.1.0 \
		tokio-native-tls-0.3.1 \
		tokio-rustls-0.24.1 \
		tokio-socks-0.5.1 \
		tokio-stream-0.1.14 \
		tokio-tungstenite-0.18.0 \
		tokio-util-0.7.8 \
		toml-0.5.11 \
		toml_datetime-0.6.3 \
		toml_edit-0.19.11 \
		topological-sort-0.2.2 \
		tower-0.4.13 \
		tower-http-0.4.1 \
		tower-layer-0.3.2 \
		tower-service-0.3.2 \
		tracing-0.1.37 \
		tracing-appender-0.2.2 \
		tracing-attributes-0.1.26 \
		tracing-core-0.1.31 \
		tracing-log-0.1.3 \
		tracing-subscriber-0.3.17 \
		try-lock-0.2.4 \
		tugger-common-0.10.0 \
		tugger-windows-0.10.0 \
		tugger-windows-codesign-0.10.0 \
		tungstenite-0.18.0 \
		type-map-0.4.0 \
		typenum-1.16.0 \
		ucd-trie-0.1.5 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-langid-0.9.1 \
		unic-langid-impl-0.9.1 \
		unic-langid-macros-0.9.1 \
		unic-langid-macros-impl-0.9.1 \
		unic-ucd-category-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.13 \
		unicode-ident-1.0.9 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		unindent-0.1.11 \
		untrusted-0.7.1 \
		url-2.4.0 \
		utf-8-0.7.6 \
		utf8parse-0.2.1 \
		utime-0.3.1 \
		valuable-0.1.0 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		waker-fn-1.1.0 \
		walkdir-2.3.3 \
		want-0.3.1 \
		warp-0.3.5 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-futures-0.4.37 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		wasm-streams-0.2.3 \
		web-sys-0.3.64 \
		webpki-0.22.0 \
		webpki-roots-0.22.6 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.42.0 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.1 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.0 \
		winnow-0.4.7 \
		winreg-0.5.1 \
		winreg-0.10.1 \
		wiremock-0.5.19 \
		xattr-0.2.3 \
		xml5ever-0.17.0 \
		xz2-0.1.7 \
		yasna-0.5.2 \
		zip-0.6.6 \
		zstd-0.12.3+zstd.1.5.2 \
		zstd-safe-6.0.5+zstd.1.5.4 \
		zstd-sys-2.0.8+zstd.1.5.5 \
		percent-encoding-iri@git+https://github.com/ankitects/rust-url.git?rev=bb930b8d089f4d30d7d19c12e54e66191de47b88\#bb930b8d089f4d30d7d19c12e54e66191de47b88 \
		csv,csv-core@git+https://github.com/ankitects/rust-csv.git?rev=1c9d3aab6f79a7d815c69f925a46a4590c115f90\#1c9d3aab6f79a7d815c69f925a46a4590c115f90 \
		linkcheck@git+https://github.com/ankitects/linkcheck.git?rev=184b2ca50ed39ca43da13f0b830a463861adb9ca\#184b2ca50ed39ca43da13f0b830a463861adb9ca

CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml

CARGO_BUILD=	no
CARGO_INSTALL=	no

CARGO_TARGET_DIR=	${WRKSRC}/out/rust

# Custom variables introduced to the runner build system via patches
MAKE_ENV+=	NO_BUNDLE=1 \
		NO_VENV=1 \
		OFFLINE_BUILD=1 \
		OFFLINE_YARNCACHE=${_MY_YARNCACHE}
# Variables already known and used by the "runner" build system
MAKE_ENV+=	NODE_BINARY=${LOCALBASE}/bin/node \
		PROTOC_BINARY=${LOCALBASE}/bin/protoc \
		PYTHON_BINARY=${PYTHON_CMD} \
		YARN_BINARY=${LOCALBASE}/bin/yarn \
		out=${WRKSRC}/out
# If RELEASE is unset the "runner" build system omits the
# "--release" flag for cargo(1).
.if !defined(WITH_DEBUG)
MAKE_ENV+=	RELEASE=1
.endif

OPTIONS_DEFAULT=	MPV
OPTIONS_GROUP=		PLAYER
OPTIONS_GROUP_PLAYER=	MPLAYER MPV
OPTIONS_SUB=		yes

MPV_DESC=	mpv media player support

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

# Should contain the most recent commit that reflects ${DISTVERSION} and must
# be exactly 8 digits otherwise the check for newer versions won't work as
# expected.
_MY_BUILDHASH=	70506aeb
# Remove ${CARGO_BUILD_TARGET} from ${CARGO_ENV} to avoid problems with
# hardcoded paths as the "runner" build system expects its components
# in ${WRKSRC}/out/rust/debug
_MY_CARGO_ENV=	${CARGO_ENV:C/CARGO_BUILD_TARGET=.+//}
# Path of the cache that is used by www/yarn
_MY_YARNCACHE=	${WRKDIR}/.yarn

post-extract:
# Some parts of the runner build system expects to be in a git repository
	@${TOUCH} ${WRKSRC}/.git
# Prepare the virtual repositories for the translation files
	@${RM} -r ${WRKSRC}/ftl/core-repo ${WRKSRC}/ftl/qt-repo
	@${RLN} ${WRKSRC_ftlrslib} ${WRKSRC}/ftl/core-repo
	@${RLN} ${WRKSRC_ftlextra} ${WRKSRC}/ftl/qt-repo

post-patch:
	@${REINPLACE_CMD} -e 's|\@PREFIX\@|${PREFIX}|' \
		${WRKSRC}/qt/tools/runanki.system.in

pre-configure:
	# Create paths for the Python pseudo venv and link some binaries to it.
	${MKDIR} ${WRKSRC}/out/pyenv/bin
	${LN} -s ${PYTHON_CMD} ${WRKSRC}/out/pyenv/bin/python
	${LN} -s ${LOCALBASE}/bin/protoc-gen-mypy ${WRKSRC}/out/pyenv/bin/protoc-gen-mypy

# Overview of the build process
#
# 1. The "runner" build system is built explicitly with the "--release" flag
#     to avoid issues with hardcoded paths.  Once completed the binaries are
#     placed into ${WRKSRC}/out/rust/release.
# 2. As soon as step 1 is finished, the "runner" build system is executed,
#    which then processes the following steps:
#    * build remaining components of "runner" (= ninja_gen, configure, etc.)
#    * generate the ninja file and run ninja afterwards
#    * create the Python wheel files in ${WRKSRC}/out/wheels
pre-build:
	${ECHO_CMD} -e "${_MY_BUILDHASH}" >> ${WRKSRC}/out/buildhash
	${ECHO_MSG} "===> Building runner build framework"
	cd ${WRKSRC} && ${SET_ENV} ${MAKE_ENV} ${_MY_CARGO_ENV} \
		${CARGO} build --package runner --release --verbose --verbose
do-build:
	${ECHO_MSG} "===> Executing runner build framework"
	cd ${WRKSRC} && ${SET_ENV} ${MAKE_ENV} ${_MY_CARGO_ENV} \
		${WRKSRC}/out/rust/release/runner build wheels

post-build:
	${MKDIR} ${WRKSRC}/out/dist
	cd ${WRKSRC}/out/wheels \
		&& ${UNZIP_NATIVE_CMD} -d ${WRKSRC}/out/dist -x *.orig anki*.whl \
		&& ${UNZIP_NATIVE_CMD} -d ${WRKSRC}/out/dist -x *.orig aqt*.whl
# Update the timestamps otherwise the set dates of the wheels
# (= 1980-01-01 00:00:00) are used
	${FIND} ${WRKSRC}/out/dist -type f -exec ${TOUCH} {} +

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/_aqt \
			${STAGEDIR}${DATADIR}/anki \
			${STAGEDIR}${DATADIR}/aqt \
			${STAGEDIR}${PREFIX}/share/pixmaps \
			${STAGEDIR}${PREFIX}/share/applications
	cd ${WRKSRC}/out/dist/ \
		&& ${COPYTREE_SHARE} _aqt ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} anki ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} aqt ${STAGEDIR}${DATADIR} "! -name .gitignore"
	cd ${WRKSRC}/qt/bundle/lin \
		&& ${INSTALL_DATA} anki.xpm anki.png ${STAGEDIR}${PREFIX}/share/pixmaps \
		&& ${INSTALL_DATA} anki.desktop ${STAGEDIR}${PREFIX}/share/applications \
		&& ${INSTALL_MAN} anki.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/qt/tools \
		&& ${INSTALL_SCRIPT} runanki.system.in ${STAGEDIR}${PREFIX}/bin/anki
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/anki/_rsbridge.so

# Helper target to make the generation of the yarn cache easier
make-yarn-cache: patch
	@${RM} -r ${_MY_YARNCACHE}
	@cd ${WRKSRC} \
		&& ${LOCALBASE}/bin/yarn --cache-folder ${_MY_YARNCACHE} install --ignore-scripts
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX} .yarn \
		&& ${ECHO_CMD} "Please upload the file ${WRKDIR}/${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
