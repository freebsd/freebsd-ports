PORTNAME=	pylyzer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.61
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static code analyzer & language server for Python
WWW=		https://mtshiba.github.io/pylyzer/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: cannot transmute between types of different sizes, or dependently-sized types, see https://github.com/RustPython/Parser/issues/116

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		git:devel/git

USES=		cargo python
USE_PYTHON=	pep517 noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	mtshiba

CARGO_CRATES=	Inflector-0.11.4 \
		addr2line-0.22.0 \
		adler-1.0.2 \
		ahash-0.8.11 \
		anyhow-1.0.86 \
		autocfg-1.3.0 \
		backtrace-0.3.73 \
		backtrace-on-stack-overflow-0.3.0 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		cc-1.1.12 \
		cfg-if-1.0.0 \
		convert_case-0.4.0 \
		crunchy-0.2.2 \
		derive_more-0.99.18 \
		either-1.13.0 \
		els-0.1.54-nightly.5 \
		erg_common-0.6.42-nightly.5 \
		erg_compiler-0.6.42-nightly.5 \
		erg_parser-0.6.42-nightly.5 \
		erg_proc_macros-0.6.42-nightly.5 \
		form_urlencoded-1.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		gimli-0.29.0 \
		hashbrown-0.14.5 \
		idna-0.5.0 \
		is-macro-0.3.6 \
		itertools-0.11.0 \
		itoa-1.0.11 \
		lalrpop-util-0.20.2 \
		libc-0.2.156 \
		libm-0.2.8 \
		lock_api-0.4.12 \
		log-0.4.22 \
		lsp-types-0.93.2 \
		malachite-0.4.14 \
		malachite-base-0.4.14 \
		malachite-bigint-0.2.0 \
		malachite-nz-0.4.14 \
		malachite-q-0.4.14 \
		memchr-2.7.4 \
		memoffset-0.6.5 \
		miniz_oxide-0.7.4 \
		molc-0.3.0 \
		nix-0.23.2 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		object-0.36.3 \
		once_cell-1.19.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		paste-1.0.15 \
		percent-encoding-2.3.1 \
		phf-0.11.2 \
		phf_codegen-0.11.2 \
		phf_generator-0.11.2 \
		phf_shared-0.11.2 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.3 \
		rustc-demangle-0.1.24 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.0 \
		ryu-1.0.18 \
		scopeguard-1.2.0 \
		semver-1.0.23 \
		serde-1.0.208 \
		serde_derive-1.0.208 \
		serde_json-1.0.125 \
		serde_repr-0.1.19 \
		shlex-1.3.0 \
		siphasher-0.3.11 \
		smallvec-1.13.2 \
		static_assertions-1.1.0 \
		syn-1.0.109 \
		syn-2.0.74 \
		thread_local-1.1.8 \
		tiny-keccak-2.0.2 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-emoji-char-0.9.0 \
		unic-ucd-ident-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-width-0.1.13 \
		unicode-xid-0.2.4 \
		unicode_names2-1.2.2 \
		unicode_names2_generator-1.2.2 \
		url-2.5.2 \
		version_check-0.9.5 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		rustpython-ast,rustpython-parser,rustpython-parser-core,rustpython-parser-vendored@git+https://github.com/RustPython/Parser\#a5b08096a0b77e8f39cd6abdc998bb770dd0c79b

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pylyzer

.include <bsd.port.mk>
