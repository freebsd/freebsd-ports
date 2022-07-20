PORTNAME=	anki
DISTVERSION=	2.1.49
PORTREVISION=	3
# Don't forget to update ${_MY_BUILDHASH} if DISTVERSION changes
CATEGORIES=	games education python
MASTER_SITES=	LOCAL/kai/:yarncache
DISTFILES=	anki-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}:yarncache

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	needs adjustments (e.g. "//platforms:freebsd_arm64") for the shipped Bazel rules files to include several files during build.

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the bazel build framework supports only 64-bit systems.

BUILD_DEPENDS=	bash:shells/bash \
		bazel:devel/bazel \
		esbuild:devel/esbuild \
		protoc:devel/protobuf \
		yarn:www/yarn \
		${PYTHON_PKGNAMEPREFIX}mypy-protobuf>=1.21:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>0:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fluent>0:devel/py-fluent@${PY_FLAVOR} \
		${RUN_DEPENDS}

# For x64 architectures there's also a Python package "orjson" that still needs
# to be ported once the required features (= "untagged unions",
# "specialication" and "const_generics") of the "smallvec" crate are available
# in the Rust release channel.
#
# Although the "orjson" package is required via the setup.py of Anki's Python
# library it's (still) optional in the code.
RUN_DEPENDS=	lame:audio/lame \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>0:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR}

# USES=ssl is required for the compilation of the Rust code
USES=		cargo desktop-file-utils pyqt:5 python:3.8+ shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ankitects
# Translation files
GH_TUPLE=	ankitects:anki-core-i18n:56d46d6:ftlrslib \
		ankitects:anki-desktop-ftl:5359f84:ftlextra
# Bazel Skylib framework and sets of bazel rules
GH_TUPLE+=	bazelbuild:bazel-skylib:e59b620:bzlskylib \
		bazelbuild:rules_cc:40548a2:bzlrcc \
		bazelbuild:rules_java:c13e3ea:bzlrjava \
		bazelbuild:rules_nodejs:2d02e82:bzlrnodejs \
		bazelbuild:rules_proto:f7a30f6:bzlrproto \
		ankitects:esbuild_toolchain:f942aa9:esbuildtc \
		ankitects:rules_pip:fb02cb7:bzlrpip \
		ankitects:rules_python:3927c9b:bzlrpython \
		ankitects:rules_rust:f66001a:bzlrrust \
		ankitects:rules_sass:275ace7:bzlrsass

USE_PYQT=	pyqt5 sip webengine

SHEBANG_FILES=	qt/tools/runanki.system.in

CARGO_CRATES=	Inflector-0.11.4 \
		adler-1.0.2 \
		ahash-0.7.4 \
		aho-corasick-0.7.18 \
		ammonia-3.1.2 \
		anyhow-1.0.42 \
		arc-swap-1.3.0 \
		arrayref-0.3.6 \
		arrayvec-0.4.12 \
		arrayvec-0.5.2 \
		askama-0.10.5 \
		askama_derive-0.10.5 \
		askama_escape-0.10.1 \
		askama_shared-0.11.1 \
		async-trait-0.1.51 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		bitvec-0.19.5 \
		blake3-0.3.8 \
		bumpalo-3.7.0 \
		byteorder-1.4.3 \
		bytes-1.0.1 \
		cc-1.0.69 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		coarsetime-0.1.19 \
		codespan-0.11.1 \
		codespan-reporting-0.11.1 \
		constant_time_eq-0.1.5 \
		convert_case-0.4.0 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-utils-0.8.5 \
		crypto-mac-0.8.0 \
		cssparser-0.27.2 \
		cssparser-macros-0.6.0 \
		ctor-0.1.20 \
		derivative-2.2.0 \
		derive_more-0.99.16 \
		digest-0.9.0 \
		dirs-2.0.2 \
		dirs-sys-0.3.6 \
		dtoa-0.4.8 \
		dtoa-short-0.3.3 \
		dunce-1.0.2 \
		either-1.6.1 \
		encoding_rs-0.8.28 \
		env_logger-0.8.4 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		fixedbitset-0.2.0 \
		flate2-1.0.20 \
		fluent-0.15.0 \
		fluent-bundle-0.15.1 \
		fluent-langneg-0.13.0 \
		fluent-syntax-0.11.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		funty-1.1.0 \
		futf-0.1.4 \
		futures-0.3.16 \
		futures-channel-0.3.16 \
		futures-core-0.3.16 \
		futures-executor-0.3.16 \
		futures-io-0.3.16 \
		futures-macro-0.3.16 \
		futures-sink-0.3.16 \
		futures-task-0.3.16 \
		futures-util-0.3.16 \
		fxhash-0.2.1 \
		generic-array-0.14.4 \
		getopts-0.2.21 \
		getrandom-0.1.16 \
		getrandom-0.2.3 \
		ghost-0.1.2 \
		h2-0.3.3 \
		hashbrown-0.11.2 \
		hashlink-0.7.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		html5ever-0.25.1 \
		htmlescape-0.3.1 \
		http-0.2.4 \
		http-body-0.4.2 \
		httparse-1.4.1 \
		httpdate-1.0.1 \
		humansize-1.1.1 \
		humantime-2.1.0 \
		hyper-0.14.11 \
		hyper-rustls-0.22.1 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		indoc-0.3.6 \
		indoc-impl-0.3.6 \
		inflections-1.1.1 \
		instant-0.1.10 \
		intl-memoizer-0.5.1 \
		intl_pluralrules-7.0.1 \
		inventory-0.1.10 \
		inventory-impl-0.1.10 \
		ipnet-2.3.1 \
		itertools-0.9.0 \
		itertools-0.10.1 \
		itoa-0.4.7 \
		js-sys-0.3.52 \
		kuchiki-0.8.1 \
		lazy_static-1.4.0 \
		lexical-core-0.7.6 \
		libc-0.2.98 \
		libsqlite3-sys-0.22.2 \
		linkify-0.5.0 \
		lock_api-0.4.4 \
		log-0.4.14 \
		mac-0.1.1 \
		maplit-1.0.2 \
		markup5ever-0.10.1 \
		markup5ever_rcdom-0.1.0 \
		matches-0.1.8 \
		memchr-2.4.0 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.4 \
		mio-0.7.13 \
		miow-0.3.7 \
		multimap-0.8.3 \
		native-tls-0.2.7 \
		new_debug_unreachable-1.0.4 \
		nodrop-0.1.14 \
		nom-6.1.2 \
		nom-7.0.0-alpha1 \
		ntapi-0.3.6 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		num_enum-0.5.2 \
		num_enum_derive-0.5.2 \
		once_cell-1.8.0 \
		openssl-0.10.35 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.65 \
		ouroboros-0.9.5 \
		ouroboros_macro-0.9.5 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		paste-0.1.18 \
		paste-impl-0.1.18 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		petgraph-0.5.1 \
		phf-0.8.0 \
		phf-0.9.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_generator-0.9.0 \
		phf_macros-0.8.0 \
		phf_macros-0.9.0 \
		phf_shared-0.8.0 \
		phf_shared-0.9.0 \
		pin-project-1.0.8 \
		pin-project-internal-1.0.8 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		precomputed-hash-0.1.1 \
		proc-macro-crate-1.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.28 \
		prost-0.7.0 \
		prost-build-0.7.0 \
		prost-derive-0.7.0 \
		prost-types-0.7.0 \
		pulldown-cmark-0.8.0 \
		pyo3-0.13.2 \
		pyo3-macros-0.13.2 \
		pyo3-macros-backend-0.13.2 \
		quote-1.0.9 \
		radium-0.5.3 \
		rand-0.7.3 \
		rand-0.8.4 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.3 \
		rand_hc-0.2.0 \
		rand_hc-0.3.1 \
		rand_pcg-0.2.1 \
		redox_syscall-0.2.9 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.4 \
		ring-0.16.20 \
		rusqlite-0.25.3 \
		rustc-hash-1.1.0 \
		rustc_version-0.3.3 \
		rustls-0.19.1 \
		rustls-native-certs-0.5.0 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		sct-0.6.1 \
		security-framework-2.3.1 \
		security-framework-sys-2.3.0 \
		selectors-0.22.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.127 \
		serde-aux-2.2.0 \
		serde_derive-1.0.127 \
		serde_json-1.0.66 \
		serde_repr-0.1.7 \
		serde_tuple-0.5.0 \
		serde_tuple_macros-0.5.0 \
		serde_urlencoded-0.7.0 \
		servo_arc-0.1.1 \
		sha1-0.6.0 \
		siphasher-0.3.6 \
		slab-0.4.3 \
		slog-2.7.0 \
		slog-async-2.7.0 \
		slog-envlogger-2.2.0 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.6.0 \
		smallvec-1.6.1 \
		socket2-0.4.1 \
		spin-0.5.2 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		string_cache-0.8.1 \
		string_cache_codegen-0.5.1 \
		strum-0.21.0 \
		strum_macros-0.21.1 \
		subtle-2.4.1 \
		syn-1.0.74 \
		take_mut-0.2.2 \
		tap-1.0.1 \
		tempfile-3.2.0 \
		tendril-0.4.2 \
		term-0.6.1 \
		termcolor-1.1.2 \
		thin-slice-0.1.1 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		thread_local-1.1.3 \
		time-0.1.44 \
		tinystr-0.3.4 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.9.0 \
		tokio-macros-1.3.0 \
		tokio-native-tls-0.3.0 \
		tokio-rustls-0.22.0 \
		tokio-socks-0.5.1 \
		tokio-util-0.6.7 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.26 \
		tracing-core-0.1.18 \
		try-lock-0.2.3 \
		type-map-0.4.0 \
		typenum-1.13.0 \
		ucd-trie-0.1.3 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-langid-0.9.0 \
		unic-langid-impl-0.9.0 \
		unic-langid-macros-0.9.0 \
		unic-langid-macros-impl-0.9.0 \
		unic-ucd-category-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		unindent-0.1.7 \
		untrusted-0.7.1 \
		url-2.2.2 \
		utf-8-0.7.6 \
		utf8-decode-1.0.1 \
		utime-0.3.1 \
		vcpkg-0.2.15 \
		version_check-0.9.3 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.75 \
		wasm-bindgen-backend-0.2.75 \
		wasm-bindgen-futures-0.4.25 \
		wasm-bindgen-macro-0.2.75 \
		wasm-bindgen-macro-support-0.2.75 \
		wasm-bindgen-shared-0.2.75 \
		web-sys-0.3.52 \
		webpki-0.21.4 \
		webpki-roots-0.21.1 \
		which-4.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		wyz-0.2.0 \
		xml5ever-0.16.1 \
		zip-0.5.13 \
		reqwest@git+https://github.com/ankitects/reqwest.git?rev=7591444614de02b658ddab125efba7b2bb4e2335\#7591444614de02b658ddab125efba7b2bb4e2335 \
		hyper-timeout@git+https://github.com/ankitects/hyper-timeout.git?rev=0cb6f7d14c62819e37cd221736f8b0555e823712\#0cb6f7d14c62819e37cd221736f8b0555e823712 \
		linkcheck@git+https://github.com/ankitects/linkcheck.git?rev=2f20798ce521cc594d510d4e417e76d5eac04d4b\#2f20798ce521cc594d510d4e417e76d5eac04d4b \
		tokio-io-timeout@git+https://github.com/ankitects/tokio-io-timeout.git?rev=1ee0892217e9a76bba4bb369ec5fab8854935a3c\#1ee0892217e9a76bba4bb369ec5fab8854935a3c \
		pct-str@git+https://github.com/timothee-haudebourg/pct-str.git?rev=4adccd8d4a222ab2672350a102f06ae832a0572d\#4adccd8d4a222ab2672350a102f06ae832a0572d
CARGO_CARGOTOML=	${WRKSRC}/pylib/rsbridge/Cargo.toml

CARGO_BUILD=	no
CARGO_INSTALL=	no

# BAZEL=1 is required otherwise ${WRKSRC}/rslib/build/main.rs produces a dummy
# buildinfo.txt that doesn't contain the actual build hash.
CARGO_ENV=	BAZEL=1 \
		BUILDINFO=${_MY_LOCALREPO}/rust_output/buildinfo.txt \
		PYO3_PYTHON=${PYTHON_CMD} \
		PROTO_TOP=${WRKSRC}/proto/.top_level \
		PROTOC=${LOCALBASE}/bin/protoc \
		BACKEND_PROTO=${WRKSRC}/rslib/backend.proto \
		RSLIB_FTL_ROOT=${_MY_LOCALREPO}/ftlrslib/l10n.toml \
		EXTRA_FTL_ROOT=${_MY_LOCALREPO}/ftlextra/l10n.toml

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
_MY_BUILDHASH=	dc80804a
# Path of the local bazel repositories
_MY_LOCALREPO=	${WRKSRC}/local_repos
# Path of cache that is used by www/yarn
_MY_YARNCACHE=	${WRKDIR}/.yarn

post-extract:
	# Create a configuration file for bazel
	@${ECHO_CMD} "startup --batch" > ${WRKSRC}/user.bazelrc
	# Create local repositories which are used by bazel
	@${MKDIR} ${_MY_LOCALREPO} \
		${_MY_LOCALREPO}/local_esbuild/bin \
		${_MY_LOCALREPO}/local_node/node/bin \
		${_MY_LOCALREPO}/local_node/node/lib \
		${_MY_LOCALREPO}/local_node/yarn/bin \
		${_MY_LOCALREPO}/protoc_bin_freebsd/bin \
		${_MY_LOCALREPO}/pyqt5 \
		${_MY_LOCALREPO}/rust_output/librsbridge \
		${_MY_LOCALREPO}/rust_output/strings_json
	# Create empty WORKSPACE files in the top directory of each local
	# repository
	@${TOUCH} ${_MY_LOCALREPO}/local_esbuild/WORKSPACE \
		${_MY_LOCALREPO}/local_node/WORKSPACE \
		${_MY_LOCALREPO}/protoc_bin_freebsd/WORKSPACE \
		${_MY_LOCALREPO}/pyqt5/WORKSPACE \
		${_MY_LOCALREPO}/rust_output/WORKSPACE
	# Copy the bazel rules for NodeJS and esbuild to the custom local repository
	# as they need some patching
	@${CP} -r ${WRKSRC_esbuildtc} ${_MY_LOCALREPO}/esbuild_toolchain
	@${CP} -r ${WRKSRC_bzlrnodejs} ${_MY_LOCALREPO}/rules_nodejs
	# Link the remaining bazel rules into the custom local repository as
	# they don't need to be patched
.for _dir in bzlskylib bzlrcc bzlrjava bzlrpip bzlrproto bzlrpython bzlrrust bzlrsass ftlextra ftlrslib
	@${RLN} ${WRKSRC_${_dir}} ${_MY_LOCALREPO}/${_dir:S/bzlr/rules_/}
.endfor
	# Copy custom BUILD.bazel files to the local repositories
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-local_esbuild \
		${_MY_LOCALREPO}/local_esbuild/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-local_node \
		${_MY_LOCALREPO}/local_node/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-protoc_bin_freebsd \
		${_MY_LOCALREPO}/protoc_bin_freebsd/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-pyqt5 \
		${_MY_LOCALREPO}/pyqt5/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-rust_output-librsbridge \
		${_MY_LOCALREPO}/rust_output/librsbridge/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-rust_output-strings_json \
		${_MY_LOCALREPO}/rust_output/strings_json/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-i18n ${WRKSRC_ftlrslib}/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-i18n ${WRKSRC_ftlextra}/BUILD.bazel
	# Move some files out of the way as they will be replaced by custom copies.
	@${MV} ${WRKSRC}/repos.bzl ${WRKSRC}/repos.bzl.dist
	@${MV} ${WRKSRC}/pip/pyqt5/defs.bzl ${WRKSRC}/pip/pyqt5/defs.bzl.dist
	@${MV} ${WRKSRC}/pylib/rsbridge/BUILD.bazel ${WRKSRC}/pylib/rsbridge/BUILD.bazel.dist
	@${MV} ${WRKSRC}/rslib/i18n/BUILD.bazel ${WRKSRC}/rslib/i18n/BUILD.bazel.dist
	# Copy the replacement files
	@${CP} ${FILESDIR}/bazel/repos.bzl ${WRKSRC}/
	@${CP} ${FILESDIR}/bazel/pyqt5.bzl ${WRKSRC}/pip/pyqt5/defs.bzl
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-pylib-rsbridge \
		${WRKSRC}/pylib/rsbridge/BUILD.bazel
	@${CP} ${FILESDIR}/bazel/BUILD.bazel-rslib-i18n \
		${WRKSRC}/rslib/i18n/BUILD.bazel

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${_MY_LOCALREPO}/rules_nodejs/internal/node/node_patches.js
	@${REINPLACE_CMD} -e 's|\@PREFIX\@|${PREFIX}|' \
		${WRKSRC}/qt/tools/runanki.system.in
	@${REINPLACE_CMD} -e 's|%%_MY_BUILDHASH%%|${_MY_BUILDHASH}|' \
		${WRKSRC}/scripts/status.sh
	@${REINPLACE_CMD} -e 's|%%_MY_LOCALREPO%%|${_MY_LOCALREPO}|g' \
		${WRKSRC}/repos.bzl ${WRKSRC}/proto/protobuf.bzl \
		${_MY_LOCALREPO}/esbuild_toolchain/esbuild_repo.bzl
	@${REINPLACE_CMD} -e 's|%%_MY_YARNCACHE%%|${_MY_YARNCACHE}|' \
		${_MY_LOCALREPO}/rules_nodejs/internal/npm_install/npm_install.bzl

pre-configure:
	# Link the binaries of Node, Protobuf and Yarn into the local bazel
	# repositories to provide them during build.
	${LN} -s ${LOCALBASE}/bin/protoc-gen-mypy ${WRKSRC}/pylib/tools/protoc-gen-mypy
	${LN} -s ${LOCALBASE}/bin/esbuild ${_MY_LOCALREPO}/local_esbuild/bin/esbuild
	${LN} -s ${LOCALBASE}/bin/node ${_MY_LOCALREPO}/local_node/node/bin/node
	${LN} -s ${LOCALBASE}/bin/yarn.js ${_MY_LOCALREPO}/local_node/yarn/bin/yarn.js
	${LN} -s ${LOCALBASE}/bin/protoc ${_MY_LOCALREPO}/protoc_bin_freebsd/bin/protoc

# Overview of the build process
#
# Steps 1 and 2 are built separately from the bazel build process.
#
# 1. rslib (Rust library, implictly built by step 2)
#    `-> produces ${_MY_LOCALREPO}/rust_output/strings_json/strings.json
# 2. pylib/rsbridge (Rust/Python bridge)
#    `-> produces ${_MY_LOCALREPO}/rust_output/librsbridge/librsbridge.so
# 3. The remaining components (Python, Qt5 and JS) are built by bazel
pre-build:
	# Generate buildinfo.txt which is used via BUILDINFO in ${CARGO_ENV} during
	# compilation.
	${ECHO_CMD} -e "STABLE_VERSION ${DISTVERSION}\nSTABLE_BUILDHASH ${_MY_BUILDHASH}" >> ${_MY_LOCALREPO}/rust_output/buildinfo.txt
	${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}
	# These files are required for the remaining build process via bazel so copy
	# them the local repository.
	${CP} `${FIND} ${CARGO_TARGET_DIR} -name "librsbridge.so"` ${_MY_LOCALREPO}/rust_output/librsbridge/
	${CP} `${FIND} ${CARGO_TARGET_DIR} -name "strings.json"` ${_MY_LOCALREPO}/rust_output/strings_json/

do-build:
	# Limit bazel jobs to 1 due random build failures while compiling TS files
	# via "tsc".
	cd ${WRKSRC} && \
		bazel --output_user_root="${WRKDIR}/.bazel" build \
			--action_env=PYTHON_SITE_PACKAGES="${PYTHON_SITELIBDIR}" \
			--action_env=PYTHON_SYS_EXECUTABLE="${PYTHON_CMD}" \
			--compilation_mode opt \
			--jobs 1 \
			--subcommands \
		dist

post-build:
	${TAR} -xf `${FIND} ${WRKDIR}/.bazel -name "dist.tar"` -C ${WRKSRC}
	cd ${WRKSRC}/bazel-dist && \
		${UNZIP_NATIVE_CMD} anki-${DISTVERSION}-*.whl && \
		${UNZIP_NATIVE_CMD} aqt-${DISTVERSION}-*.whl
	# Compile Anki's Python libary (pylib) and Qt5 library (aqt) to prepare
	# them for installation
	${PYTHON_CMD} -m compileall ${WRKSRC}/bazel-dist/anki
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/bazel-dist/anki
	${PYTHON_CMD} -m compileall ${WRKSRC}/bazel-dist/aqt
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/bazel-dist/aqt

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/anki \
			${STAGEDIR}${DATADIR}/aqt \
			${STAGEDIR}${PREFIX}/share/pixmaps \
			${STAGEDIR}${PREFIX}/share/applications
	cd ${WRKSRC}/bazel-dist/ \
		&& ${COPYTREE_SHARE} anki ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} aqt ${STAGEDIR}${DATADIR} "! -name .gitignore"
	cd ${WRKSRC}/qt/linux \
		&& ${INSTALL_DATA} anki.xpm anki.png ${STAGEDIR}${PREFIX}/share/pixmaps \
		&& ${INSTALL_DATA} anki.desktop ${STAGEDIR}${PREFIX}/share/applications \
		&& ${INSTALL_MAN} anki.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/qt/tools \
		&& ${INSTALL_SCRIPT} runanki.system.in ${STAGEDIR}${PREFIX}/bin/anki
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/anki/_backend/rsbridge.so

# Helper target to make the generation of the yarn cache easier
make-yarn-cache:
	# Run "make extract" before executing this target
	@${RM} -r ${_MY_YARNCACHE}
	@cd ${WRKSRC}/ts \
		&& ${LOCALBASE}/bin/yarn --cache-folder ${_MY_YARNCACHE} install
	@cd ${WRKSRC_bzlrnodejs}/packages/labs/grpc_web/ \
		&& ${LOCALBASE}/bin/yarn --cache-folder ${_MY_YARNCACHE} install
	@cd ${WRKSRC_bzlrsass}/sass \
		&& ${LOCALBASE}/bin/yarn --cache-folder ${_MY_YARNCACHE} install
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX} .yarn \
		&& ${ECHO_CMD} "Please upload the file ${WRKDIR}/${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
