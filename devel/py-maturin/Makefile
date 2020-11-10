# $FreeBSD$

PORTNAME=	maturin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/license-apache
LICENSE_FILE_MIT=	${WRKSRC}/license-mit

# Although the port builds fine on some 32-bit architectures (e.g. i386) it
# doesn't support creating 32-bit Python wheels for FreeBSD.  Thus save build
# time and skip the port at a early stage.
NOT_FOR_ARCHS=		armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the creation of 32-bit Python wheels is not supported for FreeBSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR}

USES=		cargo python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	PyO3
USE_PYTHON=	autoplist concurrent distutils

CARGO_CRATES=	addr2line-0.13.0 \
		adler-0.2.3 \
		aes-0.3.2 \
		aes-soft-0.3.3 \
		aesni-0.6.0 \
		aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		anyhow-1.0.32 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		backtrace-0.3.50 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-buffer-0.9.0 \
		block-cipher-trait-0.6.2 \
		block-modes-0.3.3 \
		block-padding-0.1.5 \
		bumpalo-3.4.0 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		bytes-0.5.6 \
		bytesize-1.0.1 \
		bzip2-0.3.3 \
		bzip2-sys-0.1.9+1.0.8 \
		cargo_metadata-0.11.1 \
		cbindgen-0.14.3 \
		cc-1.0.58 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		cpuid-bool-0.1.2 \
		crc32fast-1.2.0 \
		crypto-mac-0.7.0 \
		dbus-0.2.3 \
		digest-0.8.1 \
		digest-0.9.0 \
		dtoa-0.4.6 \
		encoding_rs-0.8.23 \
		env_logger-0.7.1 \
		fake-simd-0.1.2 \
		filetime-0.2.12 \
		flate2-1.0.16 \
		fnv-1.0.7 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-channel-0.3.5 \
		futures-core-0.3.5 \
		futures-io-0.3.5 \
		futures-macro-0.3.5 \
		futures-sink-0.3.5 \
		futures-task-0.3.5 \
		futures-util-0.3.5 \
		generic-array-0.12.3 \
		generic-array-0.14.4 \
		getrandom-0.1.14 \
		gimli-0.22.0 \
		glob-0.3.0 \
		goblin-0.2.3 \
		h2-0.2.6 \
		hashbrown-0.8.2 \
		heck-0.3.1 \
		hermit-abi-0.1.15 \
		hkdf-0.8.0 \
		hmac-0.7.1 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		human-panic-1.0.3 \
		humantime-1.3.0 \
		hyper-0.13.7 \
		hyper-rustls-0.21.0 \
		idna-0.2.0 \
		indexmap-1.5.1 \
		indoc-1.0.2 \
		iovec-0.1.4 \
		ipnet-2.3.0 \
		itoa-0.4.6 \
		js-sys-0.3.44 \
		kernel32-sys-0.2.2 \
		keyring-0.9.0 \
		lazy_static-1.4.0 \
		libc-0.2.74 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.0 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.34 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.2.4 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		object-0.20.0 \
		once_cell-1.4.0 \
		opaque-debug-0.2.3 \
		opaque-debug-0.3.0 \
		os_type-2.2.0 \
		percent-encoding-2.1.0 \
		pin-project-0.4.23 \
		pin-project-internal-0.4.23 \
		pin-project-lite-0.1.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.18 \
		plain-0.2.3 \
		platform-info-0.0.1 \
		platforms-0.2.1 \
		podio-0.1.7 \
		ppv-lite86-0.2.8 \
		pretty_env_logger-0.4.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.18 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.19 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		rand-0.6.5 \
		rand-0.7.3 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.2 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		reqwest-0.10.7 \
		ring-0.16.15 \
		rpassword-4.0.5 \
		rustc-demangle-0.1.16 \
		rustls-0.18.1 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scroll-0.10.1 \
		scroll_derive-0.10.2 \
		sct-0.6.0 \
		secret-service-1.1.0 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		semver-0.10.0 \
		semver-parser-0.7.0 \
		serde-1.0.115 \
		serde_derive-1.0.115 \
		serde_json-1.0.57 \
		serde_urlencoded-0.6.1 \
		sha2-0.8.2 \
		sha2-0.9.1 \
		shlex-0.1.1 \
		slab-0.4.2 \
		socket2-0.3.12 \
		spin-0.5.2 \
		strsim-0.8.0 \
		structopt-0.3.16 \
		structopt-derive-0.4.9 \
		subtle-1.0.0 \
		syn-1.0.38 \
		tar-0.4.29 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinyvec-0.3.3 \
		tokio-0.2.22 \
		tokio-rustls-0.14.0 \
		tokio-util-0.3.1 \
		toml-0.5.6 \
		tower-service-0.3.0 \
		tracing-0.1.19 \
		tracing-core-0.1.14 \
		try-lock-0.2.3 \
		typenum-1.12.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		unindent-0.1.6 \
		untrusted-0.7.1 \
		url-2.1.1 \
		uuid-0.8.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.67 \
		wasm-bindgen-backend-0.2.67 \
		wasm-bindgen-futures-0.4.17 \
		wasm-bindgen-macro-0.2.67 \
		wasm-bindgen-macro-support-0.2.67 \
		wasm-bindgen-shared-0.2.67 \
		web-sys-0.3.44 \
		webpki-0.21.3 \
		webpki-roots-0.19.0 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		ws2_32-sys-0.2.1 \
		xattr-0.2.2 \
		zip-0.5.6
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/maturin
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR} because the file that is generated in the first place
	# contains only the EGG files as a whole.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
