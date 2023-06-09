PORTNAME=	maturin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
PORTREVISION=	8
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings
WWW=		https://github.com/PyO3/maturin

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/license-apache
LICENSE_FILE_MIT=	${WRKSRC}/license-mit

# Although the port builds fine on some 32-bit architectures (e.g. i386) it
# doesn't support creating 32-bit Python wheels for FreeBSD.  Thus save build
# time and skip the port at a early stage.
NOT_FOR_ARCHS=		armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the creation of 32-bit Python wheels is not supported for FreeBSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.4.0:devel/py-setuptools-rust@${PY_FLAVOR}

USES=		cargo python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	PyO3
USE_PYTHON=	autoplist concurrent distutils

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		aes-0.7.5 \
		aho-corasick-0.7.18 \
		anyhow-1.0.61 \
		async-io-1.7.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.66 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-buffer-0.9.0 \
		block-buffer-0.10.2 \
		block-modes-0.8.1 \
		block-padding-0.2.1 \
		bstr-0.2.17 \
		bumpalo-3.10.0 \
		byteorder-1.4.3 \
		bytes-1.2.1 \
		bytesize-1.1.0 \
		bzip2-0.4.3 \
		bzip2-sys-0.1.11+1.0.8 \
		cab-0.4.1 \
		cache-padded-1.2.0 \
		camino-1.1.1 \
		cargo-options-0.3.1 \
		cargo-platform-0.1.2 \
		cargo-xwin-0.10.2 \
		cargo-zigbuild-0.12.0 \
		cargo_metadata-0.15.0 \
		cbindgen-0.24.3 \
		cc-1.0.73 \
		cfb-0.7.3 \
		cfg-if-1.0.0 \
		charset-0.1.3 \
		chunked_transfer-1.4.0 \
		cipher-0.3.0 \
		clap-3.2.17 \
		clap_complete-3.2.4 \
		clap_complete_fig-3.2.4 \
		clap_derive-3.2.17 \
		clap_lex-0.2.4 \
		cli-table-0.4.7 \
		combine-4.6.6 \
		concurrent-queue-1.2.4 \
		configparser-3.0.0 \
		console-0.15.1 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		cpufeatures-0.2.2 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.10 \
		crossbeam-utils-0.8.11 \
		crypto-common-0.1.6 \
		crypto-mac-0.11.1 \
		data-encoding-2.3.2 \
		derivative-2.2.0 \
		dialoguer-0.10.2 \
		digest-0.9.0 \
		digest-0.10.3 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dunce-1.0.2 \
		either-1.7.0 \
		encode_unicode-0.3.6 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		encoding_rs-0.8.31 \
		enumflags2-0.6.4 \
		enumflags2_derive-0.6.4 \
		env_logger-0.7.1 \
		fastrand-1.8.0 \
		fat-macho-0.4.5 \
		filetime-0.2.17 \
		flate2-1.0.24 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		fs-err-2.7.0 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-lite-1.12.0 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.14.6 \
		getrandom-0.2.7 \
		gimli-0.26.2 \
		glob-0.3.0 \
		globset-0.4.9 \
		goblin-0.5.3 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hkdf-0.11.0 \
		hmac-0.11.0 \
		human-panic-1.0.3 \
		humantime-1.3.0 \
		idna-0.2.3 \
		ignore-0.4.18 \
		indexmap-1.9.1 \
		indicatif-0.17.0-rc.6 \
		indoc-1.0.7 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.3 \
		js-sys-0.3.59 \
		keyring-1.2.0 \
		lazy_static-1.4.0 \
		lddtree-0.2.9 \
		libc-0.2.131 \
		lock_api-0.4.7 \
		log-0.4.17 \
		lzxd-0.1.4 \
		mailparse-0.13.8 \
		matchers-0.1.0 \
		matches-0.1.9 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mime-0.3.16 \
		mime_guess-2.0.4 \
		minijinja-0.17.0 \
		miniz_oxide-0.5.3 \
		msi-0.5.0 \
		multipart-0.18.0 \
		native-tls-0.2.10 \
		nb-connect-1.2.0 \
		nix-0.22.3 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.2 \
		num-integer-0.1.45 \
		num-iter-0.1.43 \
		num-rational-0.4.1 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		num_threads-0.1.6 \
		number_prefix-0.4.0 \
		object-0.29.0 \
		once_cell-1.13.0 \
		opaque-debug-0.3.0 \
		openssl-0.10.41 \
		openssl-macros-0.1.0 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.75 \
		os_str_bytes-6.3.0 \
		os_type-2.4.0 \
		parking-2.0.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		path-slash-0.2.1 \
		pep440-0.2.0 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.25 \
		plain-0.2.3 \
		platform-info-0.2.0 \
		polling-2.2.0 \
		ppv-lite86-0.2.16 \
		pretty_env_logger-0.4.0 \
		proc-macro-crate-0.1.5 \
		proc-macro-crate-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.43 \
		pyproject-toml-0.3.1 \
		python-pkginfo-0.5.4 \
		quick-error-1.2.3 \
		quote-1.0.21 \
		quoted_printable-0.4.5 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		rfc2047-decoder-0.1.2 \
		ring-0.16.20 \
		rpassword-7.0.0 \
		rustc-demangle-0.1.21 \
		rustc_version-0.4.0 \
		rustls-0.20.6 \
		ryu-1.0.11 \
		same-file-1.0.6 \
		schannel-0.1.20 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		scroll-0.11.0 \
		scroll_derive-0.11.0 \
		sct-0.7.0 \
		secret-service-2.0.2 \
		security-framework-2.6.1 \
		security-framework-sys-2.6.1 \
		semver-1.0.13 \
		serde-1.0.143 \
		serde_derive-1.0.143 \
		serde_json-1.0.83 \
		serde_repr-0.1.9 \
		sha2-0.9.9 \
		sha2-0.10.2 \
		sharded-slab-0.1.4 \
		slab-0.4.7 \
		smallvec-1.9.0 \
		smawk-0.3.1 \
		socket2-0.4.4 \
		socks-0.3.4 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		subtle-2.4.1 \
		syn-1.0.99 \
		tar-0.4.38 \
		target-lexicon-0.12.4 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		thiserror-1.0.32 \
		thiserror-impl-1.0.32 \
		thread_local-1.1.4 \
		time-0.3.13 \
		time-macros-0.2.4 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		toml-0.5.9 \
		toml_edit-0.14.4 \
		tracing-0.1.36 \
		tracing-attributes-0.1.22 \
		tracing-core-0.1.29 \
		tracing-serde-0.1.3 \
		tracing-subscriber-0.3.15 \
		twox-hash-1.6.3 \
		typenum-1.15.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.3 \
		unicode-linebreak-0.1.2 \
		unicode-normalization-0.1.21 \
		unicode-width-0.1.9 \
		untrusted-0.7.1 \
		ureq-2.5.0 \
		url-2.2.2 \
		uuid-0.8.2 \
		uuid-1.1.2 \
		valuable-0.1.0 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		waker-fn-1.1.0 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.82 \
		wasm-bindgen-backend-0.2.82 \
		wasm-bindgen-macro-0.2.82 \
		wasm-bindgen-macro-support-0.2.82 \
		wasm-bindgen-shared-0.2.82 \
		web-sys-0.3.59 \
		webpki-0.22.0 \
		webpki-roots-0.22.4 \
		wepoll-ffi-0.1.2 \
		which-4.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1 \
		xattr-0.2.3 \
		xwin-0.2.5 \
		zbus-1.9.3 \
		zbus_macros-1.9.3 \
		zip-0.6.2 \
		zvariant-2.10.0 \
		zvariant_derive-2.10.0

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TARGET_DIR=	${WRKSRC}/target
MAKE_ENV=	${CARGO_ENV}
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
CARGO_BUILD_ARGS=	--no-default-features \
			--features=upload,log,human-panic
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=0.10.1:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=0.10.1:textproc/py-tomli@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml

# The binary is usually built via setup.py which uses different compiler flags.
# That line is patched out there to use the compiler flags from the Ports
# framework instead.  The setup.py is processed in the "do-build" target to
# install the compiled binary.
pre-build:
	${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}

post-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/maturin ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/maturin
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR} because the file that is generated in the first place
	# contains only the EGG files as a whole.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.post.mk>
