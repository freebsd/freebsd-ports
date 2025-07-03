PORTNAME=	dhall
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.15
PORTREVISION=	9
CATEGORIES=	lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for dhall, a functional configuration language
WWW=		https://github.com/s-zeng/dhall-python

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		gmake:devel/gmake
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=5.0:devel/py-flake8@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=2.6:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		cargo perl5 python
USE_PYTHON=	pep517 autoplist pytest
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	s-zeng
GH_PROJECT=	dhall-python

CARGO_CRATES=	abnf-0.12.0 \
		abnf-core-0.5.0 \
		abnf_to_pest-0.5.1 \
		annotate-snippets-0.9.1 \
		arrayvec-0.5.2 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-buffer-0.7.3 \
		block-buffer-0.10.2 \
		block-padding-0.1.5 \
		bumpalo-3.12.0 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		cpufeatures-0.2.2 \
		crunchy-0.2.2 \
		crypto-common-0.1.6 \
		dhall-0.12.0 \
		dhall_proc_macros-0.6.1 \
		digest-0.8.1 \
		digest-0.10.3 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		elsa-1.7.0 \
		encoding_rs-0.8.30 \
		fake-simd-0.1.2 \
		fastrand-1.7.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-io-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.12.4 \
		generic-array-0.14.5 \
		h2-0.3.17 \
		half-1.8.2 \
		half-2.1.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		home-0.5.3 \
		http-0.2.6 \
		http-body-0.4.4 \
		httparse-1.6.0 \
		httpdate-1.0.2 \
		hyper-0.14.18 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		indexmap-1.8.1 \
		indoc-1.0.4 \
		instant-0.1.12 \
		ipnet-2.4.0 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		lock_api-0.4.6 \
		log-0.4.16 \
		maplit-1.0.2 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memoffset-0.9.0 \
		mime-0.3.16 \
		minicbor-0.18.0 \
		minicbor-derive-0.12.0 \
		minimal-lexical-0.2.1 \
		mio-0.8.5 \
		native-tls-0.2.10 \
		nom-7.1.1 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		opaque-debug-0.2.3 \
		openssl-0.10.54 \
		openssl-macros-0.1.0 \
		openssl-probe-0.1.5 \
		openssl-src-111.25.2+1.1.1t \
		openssl-sys-0.9.88 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_consume-1.1.1 \
		pest_consume_macros-1.1.0 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkg-config-0.3.24 \
		pretty-0.11.3 \
		proc-macro2-1.0.54 \
		pyo3-0.19.0 \
		pyo3-build-config-0.19.0 \
		pyo3-ffi-0.19.0 \
		pyo3-macros-0.19.0 \
		pyo3-macros-backend-0.19.0 \
		quote-1.0.26 \
		redox_syscall-0.2.12 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.10 \
		ryu-1.0.9 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		security-framework-2.6.1 \
		security-framework-sys-2.6.1 \
		serde-1.0.164 \
		serde_derive-1.0.164 \
		serde_dhall-0.12.1 \
		serde_json-1.0.97 \
		serde_urlencoded-0.7.1 \
		sha-1-0.8.2 \
		sha2-0.10.2 \
		slab-0.4.5 \
		smallvec-1.8.0 \
		socket2-0.4.4 \
		stable_deref_trait-1.2.0 \
		syn-1.0.105 \
		syn-2.0.11 \
		target-lexicon-0.12.3 \
		tempfile-3.3.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.25.0 \
		tokio-native-tls-0.3.0 \
		tokio-util-0.7.7 \
		tower-service-0.3.1 \
		tracing-0.1.32 \
		tracing-core-0.1.23 \
		try-lock-0.2.3 \
		typed-arena-2.0.1 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.7 \
		unicode-ident-1.0.5 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unindent-0.1.8 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		want-0.3.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-futures-0.4.29 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		winreg-0.10.1

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
