PORTNAME=	pylyzer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.78
PORTREVISION=	4
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static code analyzer & language server for Python
WWW=		https://mtshiba.github.io/pylyzer/ \
		https://github.com/mtshiba/pylyzer

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

CARGO_CRATES=	addr2line-0.24.2 \
		adler2-2.0.0 \
		ahash-0.8.11 \
		anyhow-1.0.95 \
		autocfg-1.4.0 \
		backtrace-0.3.74 \
		backtrace-on-stack-overflow-0.3.0 \
		bitflags-1.3.2 \
		bitflags-2.8.0 \
		bumpalo-3.17.0 \
		byteorder-1.5.0 \
		cc-1.2.10 \
		cfg-if-1.0.0 \
		convert_case-0.4.0 \
		crunchy-0.2.3 \
		derive_more-0.99.18 \
		displaydoc-0.2.5 \
		either-1.13.0 \
		els-0.1.64-nightly.1 \
		erg_common-0.6.52-nightly.1 \
		erg_compiler-0.6.52-nightly.1 \
		erg_parser-0.6.52-nightly.1 \
		erg_proc_macros-0.6.52-nightly.1 \
		form_urlencoded-1.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		gimli-0.31.1 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		icu_collections-1.5.0 \
		icu_locid-1.5.0 \
		icu_locid_transform-1.5.0 \
		icu_locid_transform_data-1.5.0 \
		icu_normalizer-1.5.0 \
		icu_normalizer_data-1.5.0 \
		icu_properties-1.5.1 \
		icu_properties_data-1.5.0 \
		icu_provider-1.5.0 \
		icu_provider_macros-1.5.0 \
		idna-1.0.3 \
		idna_adapter-1.2.0 \
		is-macro-0.3.7 \
		itertools-0.11.0 \
		itoa-1.0.14 \
		lalrpop-util-0.20.2 \
		libc-0.2.169 \
		libm-0.2.11 \
		litemap-0.7.4 \
		lock_api-0.4.12 \
		log-0.4.25 \
		lsp-types-0.93.2 \
		malachite-0.4.18 \
		malachite-base-0.4.18 \
		malachite-bigint-0.2.0 \
		malachite-nz-0.4.18 \
		malachite-q-0.4.18 \
		memchr-2.7.4 \
		memoffset-0.6.5 \
		miniz_oxide-0.8.3 \
		molc-0.3.0 \
		nix-0.23.2 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		object-0.36.7 \
		once_cell-1.20.2 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		paste-1.0.15 \
		percent-encoding-2.3.1 \
		phf-0.11.3 \
		phf_codegen-0.11.3 \
		phf_generator-0.11.3 \
		phf_shared-0.11.3 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.93 \
		quote-1.0.38 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.8 \
		rustc-demangle-0.1.24 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.1 \
		rustversion-1.0.19 \
		ryu-1.0.19 \
		scopeguard-1.2.0 \
		semver-1.0.25 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.138 \
		serde_repr-0.1.19 \
		shlex-1.3.0 \
		siphasher-1.0.1 \
		smallvec-1.13.2 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		syn-1.0.109 \
		syn-2.0.96 \
		synstructure-0.13.1 \
		thread_local-1.1.8 \
		tiny-keccak-2.0.2 \
		tinystr-0.7.6 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-emoji-char-0.9.0 \
		unic-ucd-ident-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-ident-1.0.16 \
		unicode-width-0.1.14 \
		unicode-xid-0.2.6 \
		unicode_names2-1.3.0 \
		unicode_names2_generator-1.3.0 \
		url-2.5.4 \
		utf16_iter-1.0.5 \
		utf8_iter-1.0.4 \
		version_check-0.9.5 \
		w-boson-0.1.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		windows-0.58.0 \
		windows-core-0.58.0 \
		windows-implement-0.58.0 \
		windows-interface-0.58.0 \
		windows-result-0.2.0 \
		windows-strings-0.1.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		write16-1.0.0 \
		writeable-0.5.5 \
		yoke-0.7.5 \
		yoke-derive-0.7.5 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		zerofrom-0.1.5 \
		zerofrom-derive-0.1.5 \
		zerovec-0.10.4 \
		zerovec-derive-0.10.3 \
		rustpython-ast,rustpython-parser,rustpython-parser-core,rustpython-parser-vendored@git+https://github.com/RustPython/Parser\#f07b97cef396d573364639904d767c9ff3e3e701

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}

.include <bsd.port.mk>
