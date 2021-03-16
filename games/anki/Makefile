# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
DISTVERSION=	2.1.35
PORTREVISION=	7
# Don't forget to update ${_MY_BUILDHASH}
CATEGORIES=	games education python
MASTER_SITES=	LOCAL/kai/:npmcache
DISTFILES=	anki-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache
DIST_SUBDIR=	python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		maturin:devel/py-maturin@${PY_FLAVOR} \
		protoc:devel/protobuf \
		npm:www/npm \
		rsync:net/rsync \
		${PYTHON_PKGNAMEPREFIX}mypy-protobuf>=1.21:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase==1.2.0:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
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
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR}

# USES=ssl is required for the compilation of the Rust code
USES=		cargo desktop-file-utils gmake perl5 pyqt:5 python:3.7+ shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ankitects
GH_TUPLE=	ankitects:anki-core-i18n:fbda2ed:i18ncore \
		ankitects:anki-desktop-ftl:f56e959:i18nfluent \
		ankitects:anki-desktop-i18n:a93ccef:i18ndesktop \
		ankitects:rust-coarsetime:f9e2c86216f0f4803bc75404828318fc206dab29:coarsetime \
		ankitects:fluent-rs:f61c5e10a53161ef5261f3c87b62047f12e4aa74:fluent \
		ankitects:hyper-timeout:664b6f9c387f6a7d75d1609a65c02554e8c55bc7:hypertimeout \
		ankitects:reqwest:57665e2c2a39db85723ba860f1b570a608bb73f9:reqwest \
		ankitects:tokio-io-timeout:96e1358555c49905de89170f2b1102a7d8b6c4c2:tokioiotimeout
USE_PERL5=	build
USE_PYQT=	core gui network printsupport sip svg webchannel webengine widgets xml_build

SHEBANG_FILES=	qt/po/scripts/build-mo-files \
		qt/po/scripts/copy-qt-files \
		qt/runanki \
		qt/tools/build_ui.sh \
		scripts/rename

CARGO_CRATES=	addr2line-0.13.0 \
		adler-0.2.3 \
		aho-corasick-0.7.14 \
		anyhow-1.0.33 \
		arc-swap-0.4.7 \
		arrayref-0.3.6 \
		arrayvec-0.4.12 \
		arrayvec-0.5.1 \
		askama-0.10.3 \
		askama_derive-0.10.3 \
		askama_escape-0.10.1 \
		askama_shared-0.10.4 \
		async-compression-0.3.5 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.53 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		blake3-0.3.7 \
		bumpalo-3.4.0 \
		byteorder-1.3.4 \
		bytes-0.4.12 \
		bytes-0.5.6 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		cloudabi-0.1.0 \
		constant_time_eq-0.1.5 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.4.4 \
		crossbeam-utils-0.7.2 \
		crypto-mac-0.8.0 \
		ctor-0.1.16 \
		derivative-2.1.1 \
		digest-0.9.0 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		dtoa-0.4.6 \
		either-1.6.1 \
		encoding_rs-0.8.24 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		fixedbitset-0.2.0 \
		flate2-1.0.18 \
		fluent-langneg-0.12.1 \
		fluent-syntax-0.9.3 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.3.6 \
		futures-channel-0.3.6 \
		futures-core-0.3.6 \
		futures-executor-0.3.6 \
		futures-io-0.3.6 \
		futures-macro-0.3.6 \
		futures-sink-0.3.6 \
		futures-task-0.3.6 \
		futures-util-0.3.6 \
		fxhash-0.2.1 \
		generic-array-0.14.4 \
		getrandom-0.1.15 \
		ghost-0.1.2 \
		gimli-0.22.0 \
		h2-0.2.6 \
		hashbrown-0.9.1 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		hex-0.4.2 \
		htmlescape-0.3.1 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		httpdate-0.3.2 \
		humansize-1.1.0 \
		hyper-0.13.8 \
		hyper-tls-0.4.3 \
		idna-0.2.0 \
		indexmap-1.6.0 \
		indoc-0.3.6 \
		indoc-impl-0.3.6 \
		instant-0.1.7 \
		intl_pluralrules-6.0.0 \
		inventory-0.1.9 \
		inventory-impl-0.1.9 \
		iovec-0.1.4 \
		itertools-0.8.2 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		js-sys-0.3.45 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lexical-core-0.7.4 \
		libc-0.2.79 \
		libsqlite3-sys-0.18.0 \
		linked-hash-map-0.5.3 \
		lock_api-0.4.1 \
		log-0.4.11 \
		lru-cache-0.1.2 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.3 \
		mio-0.6.22 \
		miow-0.2.1 \
		multimap-0.8.2 \
		native-tls-0.2.4 \
		net2-0.2.35 \
		nodrop-0.1.14 \
		nom-5.1.2 \
		num-format-0.4.0 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		num_enum-0.5.1 \
		num_enum_derive-0.5.1 \
		object-0.21.1 \
		once_cell-1.4.1 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		parking_lot-0.11.0 \
		parking_lot_core-0.8.0 \
		paste-0.1.18 \
		paste-impl-0.1.18 \
		percent-encoding-2.1.0 \
		petgraph-0.5.1 \
		pin-project-0.4.27 \
		pin-project-internal-0.4.27 \
		pin-project-lite-0.1.11 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		podio-0.1.7 \
		ppv-lite86-0.2.9 \
		proc-macro-crate-0.1.5 \
		proc-macro-hack-0.5.18 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.24 \
		prost-0.6.1 \
		prost-build-0.6.1 \
		prost-derive-0.6.1 \
		prost-types-0.6.1 \
		pyo3-0.11.1 \
		pyo3-derive-backend-0.11.1 \
		pyo3cls-0.11.1 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		remove_dir_all-0.5.3 \
		rental-0.5.5 \
		rental-impl-0.5.5 \
		rusqlite-0.23.1 \
		rust-argon2-0.8.2 \
		rustc-demangle-0.1.18 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		serde-1.0.117 \
		serde-aux-0.6.1 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		serde_repr-0.1.6 \
		serde_tuple-0.5.0 \
		serde_tuple_macros-0.5.0 \
		serde_urlencoded-0.6.1 \
		sha1-0.6.0 \
		slab-0.4.2 \
		slog-2.5.2 \
		slog-async-2.5.0 \
		slog-envlogger-2.2.0 \
		slog-scope-4.3.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.6.0 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		subtle-2.3.0 \
		syn-1.0.46 \
		synstructure-0.12.4 \
		take_mut-0.2.2 \
		tempfile-3.1.0 \
		term-0.6.1 \
		thiserror-1.0.21 \
		thiserror-impl-1.0.21 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinystr-0.3.4 \
		tinyvec-0.3.4 \
		tokio-0.2.22 \
		tokio-socks-0.2.2 \
		tokio-tls-0.3.1 \
		tokio-util-0.3.1 \
		toml-0.5.7 \
		tower-service-0.3.0 \
		tracing-0.1.21 \
		tracing-core-0.1.17 \
		try-lock-0.2.3 \
		type-map-0.3.0 \
		typenum-1.12.0 \
		unic-langid-0.8.0 \
		unic-langid-impl-0.8.0 \
		unic-langid-macros-0.8.0 \
		unic-langid-macros-impl-0.8.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-xid-0.2.1 \
		unindent-0.1.7 \
		url-2.1.1 \
		utime-0.3.1 \
		vcpkg-0.2.10 \
		version_check-0.9.2 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.68 \
		wasm-bindgen-backend-0.2.68 \
		wasm-bindgen-futures-0.4.18 \
		wasm-bindgen-macro-0.2.68 \
		wasm-bindgen-macro-support-0.2.68 \
		wasm-bindgen-shared-0.2.68 \
		web-sys-0.3.45 \
		which-3.1.1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		ws2_32-sys-0.2.1 \
		zip-0.5.6
CARGO_USE_GITHUB=	yes

CARGO_CARGOLOCK=	${WRKSRC}/rspy/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/rspy/Cargo.toml

CARGO_BUILD=	no

MAKE_ARGS=	DEVEL="rspy pylib ts qt" PYTHON_FILE="${PYTHON_CMD}" SHELL="${LOCALBASE}/bin/bash"
# devel/py-maturin  acts as a wrapper for "cargo" and "rustc".  Ensure that it
# uses the arguments/flags for Rust of the Ports framework.
MAKE_ARGS+=	BUILDFLAGS="--cargo-extra-args='${CARGO_BUILD_ARGS} --verbose'"
MAKE_ENV=	${CARGO_ENV} npm_config_offline=true

ALL_TARGET=		build

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	MPV
OPTIONS_GROUP=		PLAYER
OPTIONS_GROUP_PLAYER=	MPLAYER MPV
OPTIONS_SUB=		yes

MPV_DESC=	mpv media player support

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

NLS_USES=	gettext

# Should contain the most recent commit that reflects ${DISTVERSION} and must
# be exactly 8 digits otherwise the check for newer versions won't work as
# expected.
_MY_BUILDHASH=	84dcaa86

# Place the translation files to the appropriate directories
post-extract:
	@${RLN} ${WRKSRC_i18ncore} ${WRKSRC}/rslib/ftl/repo
	@${RLN} ${WRKSRC_i18nfluent} ${WRKSRC}/qt/ftl/repo
	@${RLN} ${WRKSRC_i18ndesktop} ${WRKSRC}/qt/po/repo

post-patch:
	# Add trailing directory names to cargo repositories
	@${REINPLACE_CMD} -Ee '/^fluent =/ s|(${WRKSRC_fluent})|\1/fluent|; \
		/^intl-memoizer =/ s|(${WRKSRC_fluent})|\1/intl-memoizer|' ${WRKSRC}/rslib/Cargo.toml
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/qt/runanki
	@${REINPLACE_CMD} -e 's|%%MAKE_CMD%%|${MAKE_CMD}|' ${WRKSRC}/qt/Makefile
	@${REINPLACE_CMD} -e 's|%%UNZIP_NATIVE_CMD%%|${UNZIP_NATIVE_CMD}|' ${WRKSRC}/rspy/Makefile

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|### NLS ###||' ${WRKSRC}/qt/Makefile

# Although PYTHON_FILE is set to ${PYTHON_CMD} via MAKE_ARGS to make the
# compilation of the pyo3 crate possible there are also hardcoded "python"
# occurences in too many places.
pre-configure:
	${MKDIR} ${WRKDIR}/.bin && ${LN} -s ${PYTHON_CMD} ${WRKDIR}/.bin/python

# Overview of the build process
#
# 1. rslib (Rust library, implictly built by step 2)
#    `-> produces ${WRKSRC}/proto/fluent.proto
# 2. rspy (Rust/Python bridge) which is built by devel/py-maturin
#    `-> produces ${WRKSRC}/pylib/ankirspy.cpython-${PYTHON_SUFFIX}m.so
# 3. pylib (Python-only library)
# 4. ts (builds ${WRKSRC}/ts/node_modules/.bin/{tsc,sass})
# 5. qt (Python library with Qt5 bindings)
pre-build:
	# Set the buildhash that is used at various places during build.
	${ECHO_CMD} ${_MY_BUILDHASH} > ${WRKSRC}/meta/buildhash

post-build:
	# Compile Anki's Python libary (pylib) and Qt5 library (aqt) to prepare
	# them for installation
	${PYTHON_CMD} -m compileall ${WRKSRC}/pylib/anki
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/pylib/anki
	${PYTHON_CMD} -m compileall ${WRKSRC}/qt/aqt
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/qt/aqt

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/anki \
			${STAGEDIR}${DATADIR}/aqt \
			${STAGEDIR}${DATADIR}/aqt_data \
			${STAGEDIR}${PREFIX}/share/pixmaps \
			${STAGEDIR}${PREFIX}/share/applications
	cd ${WRKSRC}/pylib \
		&& ${COPYTREE_SHARE} anki ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${INSTALL_LIB} *.so ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/qt \
		&& ${COPYTREE_SHARE} aqt ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} aqt_data ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${INSTALL_DATA} anki.xpm anki.png ${STAGEDIR}${PREFIX}/share/pixmaps \
		&& ${INSTALL_DATA} anki.desktop ${STAGEDIR}${PREFIX}/share/applications \
		&& ${INSTALL_MAN} anki.1 ${STAGEDIR}${MANPREFIX}/man/man1 \
		&& ${INSTALL_SCRIPT} runanki ${STAGEDIR}${PREFIX}/bin/anki

# Helper target to make the generation of the npm cache easier
#
# The command "npx pbjs" tries to install additional dependencies for the CLI
# component of the "protobufjs" package and will fail during build because the
# environment variable "npm_config_offline" is set to "true" via ${MAKE_ENV}.
#
# Thus "npx pbjs" is issued after "npm install" to get the remaining
# dependencies to populate the cache with them.
make-npm-cache:
	# Run "make extract" before executing this target
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC}/ts \
		&& ${SETENV} HOME=${WRKDIR} npm install \
		&& ${TOUCH} in.proto \
		&& ${SETENV} HOME=${WRKDIR} npx --cache ${WRKDIR}/.npm pbjs -q -t static-module in.proto -o out.proto
	@cd ${WRKDIR}/.npm \
		&& ${RM} -r _locks anonymous-cli-metrics.json
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
