PORTNAME=	SudachiPy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	japanese python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Sudachi, a Japanese morphological analyzer
WWW=		https://github.com/WorksApplications/sudachi.rs

LICENSE=	APACHE20

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
		ansi_term-0.12.1 \
		anstyle-1.0.7 \
		arbitrary-1.3.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		bumpalo-3.16.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		claim-0.5.0 \
		clap-2.34.0 \
		clap-4.5.9 \
		clap_builder-4.5.9 \
		clap_lex-0.7.1 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		crunchy-0.2.2 \
		csv-1.3.0 \
		csv-core-0.1.11 \
		either-1.13.0 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fancy-regex-0.12.0 \
		fastrand-2.1.0 \
		half-2.4.1 \
		hashbrown-0.14.5 \
		heck-0.3.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.9 \
		honggfuzz-0.5.56 \
		indexmap-2.2.6 \
		indoc-2.0.5 \
		is-terminal-0.4.12 \
		itertools-0.10.5 \
		itertools-0.12.1 \
		itoa-1.0.11 \
		js-sys-0.3.69 \
		lazy_static-1.5.0 \
		libc-0.2.155 \
		libloading-0.8.5 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.6 \
		log-0.4.22 \
		memchr-2.7.4 \
		memmap2-0.7.1 \
		memmap2-0.9.4 \
		memoffset-0.9.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.19.0 \
		oorandom-11.1.4 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		plotters-0.3.6 \
		plotters-backend-0.3.6 \
		plotters-svg-0.3.6 \
		portable-atomic-1.7.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.86 \
		pyo3-0.20.3 \
		pyo3-build-config-0.20.3 \
		pyo3-ffi-0.20.3 \
		pyo3-macros-0.20.3 \
		pyo3-macros-backend-0.20.3 \
		quote-1.0.36 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.3 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		rustc_version-0.4.0 \
		rustix-0.38.34 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.23 \
		serde-1.0.204 \
		serde_derive-1.0.204 \
		serde_json-1.0.120 \
		smallvec-1.13.2 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.109 \
		syn-2.0.71 \
		target-lexicon-0.12.15 \
		tempfile-3.10.1 \
		textwrap-0.11.0 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		thread_local-1.1.8 \
		tinytemplate-1.2.1 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.13 \
		unindent-0.2.3 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		web-sys-0.3.69 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sudachipy/sudachipy${PYTHON_EXT_SUFFIX}.so

# The sudachipy executable fails, see https://github.com/WorksApplications/sudachi.rs/issues/270

.include <bsd.port.mk>
