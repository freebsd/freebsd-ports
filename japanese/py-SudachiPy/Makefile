PORTNAME=	SudachiPy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.10
PORTREVISION=	5
CATEGORIES=	japanese python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Sudachi, a Japanese morphological analyzer
WWW=		https://github.com/WorksApplications/sudachi.rs

LICENSE=	APACHE20

BROKEN_armv7=	compilation fails: error[E0425]: cannot find value `SEED` in this scope ; constant `crate::hash::SEED` exists but is inaccessible, see https://github.com/WorksApplications/sudachi.rs/issues/298
BROKEN_i386=	compilation fails: error[E0425]: cannot find value `SEED` in this scope ; constant `crate::hash::SEED` exists but is inaccessible, see https://github.com/WorksApplications/sudachi.rs/issues/298
BROKEN_powerpc=	compilation fails: error[E0425]: cannot find value `SEED` in this scope ; constant `crate::hash::SEED` exists but is inaccessible, see https://github.com/WorksApplications/sudachi.rs/issues/298

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	WorksApplications
GH_PROJECT=	sudachi.rs

WRKSRC_SUBDIR=	python

CARGO_CRATES=	aho-corasick-1.1.3 \
		anes-0.1.6 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.6 \
		arbitrary-1.4.1 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-2.7.0 \
		bumpalo-3.16.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		claim-0.5.0 \
		clap-4.5.26 \
		clap_builder-4.5.26 \
		clap_derive-4.5.24 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crunchy-0.2.2 \
		csv-1.3.1 \
		csv-core-0.1.11 \
		either-1.13.0 \
		equivalent-1.0.1 \
		errno-0.3.10 \
		fancy-regex-0.13.0 \
		fastrand-2.3.0 \
		getrandom-0.2.15 \
		half-2.4.1 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		hermit-abi-0.4.0 \
		honggfuzz-0.5.56 \
		indexmap-2.7.0 \
		indoc-2.0.5 \
		is-terminal-0.4.13 \
		is_terminal_polyfill-1.70.1 \
		itertools-0.10.5 \
		itertools-0.13.0 \
		itoa-1.0.14 \
		js-sys-0.3.76 \
		lazy_static-1.5.0 \
		libc-0.2.169 \
		libloading-0.8.6 \
		linux-raw-sys-0.4.15 \
		log-0.4.22 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		memoffset-0.9.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.20.2 \
		oorandom-11.1.4 \
		plotters-0.3.7 \
		plotters-backend-0.3.7 \
		plotters-svg-0.3.7 \
		portable-atomic-1.10.0 \
		proc-macro2-1.0.93 \
		pyo3-0.23.4 \
		pyo3-build-config-0.23.4 \
		pyo3-ffi-0.23.4 \
		pyo3-macros-0.23.4 \
		pyo3-macros-backend-0.23.4 \
		quote-1.0.38 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustc_version-0.4.1 \
		rustix-0.38.43 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.24 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.135 \
		strsim-0.11.1 \
		syn-2.0.96 \
		target-lexicon-0.12.16 \
		tempfile-3.15.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		thread_local-1.1.8 \
		tinytemplate-1.2.1 \
		tinyvec-1.8.1 \
		tinyvec_macros-0.1.1 \
		unicode-ident-1.0.14 \
		unicode-normalization-0.1.24 \
		unindent-0.2.3 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.99 \
		wasm-bindgen-backend-0.2.99 \
		wasm-bindgen-macro-0.2.99 \
		wasm-bindgen-macro-support-0.2.99 \
		wasm-bindgen-shared-0.2.99 \
		web-sys-0.3.76 \
		winapi-util-0.1.9 \
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
		yada-0.5.1

CARGO_BUILD=		no
CARGO_INSTALL=		no

# The sudachipy executable fails, see https://github.com/WorksApplications/sudachi.rs/issues/270

.include <bsd.port.mk>
