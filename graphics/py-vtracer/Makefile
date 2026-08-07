PORTNAME=	vtracer
DISTVERSION=	0.6.15
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the Rust Vtracer raster-to-vector library
WWW=		https://www.visioncortex.org/vtracer/ \
		https://github.com/visioncortex/vtracer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.2:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist concurrent

CARGO_BUILD=	no
CARGO_INSTALL=	no

CARGO_CRATES=	adler-1.0.2 \
		adler32-1.2.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.5.0 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bitflags-2.11.0 \
		bumpalo-3.20.2 \
		bytemuck-1.25.0 \
		byteorder-1.5.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.4 \
		clap-2.34.0 \
		color_quant-1.1.0 \
		console_error_panic_hook-0.1.7 \
		console_log-0.2.2 \
		crc32fast-1.5.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		deflate-0.8.6 \
		either-1.15.0 \
		fastrand-2.3.0 \
		flo_curves-0.3.1 \
		getrandom-0.2.17 \
		gif-0.11.4 \
		hermit-abi-0.1.19 \
		image-0.23.14 \
		indoc-1.0.9 \
		itertools-0.8.2 \
		itoa-1.0.18 \
		jpeg-decoder-0.1.22 \
		js-sys-0.3.91 \
		libc-0.2.183 \
		lock_api-0.4.14 \
		log-0.4.29 \
		memchr-2.8.0 \
		memoffset-0.9.1 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.4 \
		num-integer-0.1.46 \
		num-iter-0.1.45 \
		num-rational-0.3.2 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		png-0.16.8 \
		proc-macro2-1.0.106 \
		pyo3-0.19.2 \
		pyo3-build-config-0.19.2 \
		pyo3-ffi-0.19.2 \
		pyo3-macros-0.19.2 \
		pyo3-macros-backend-0.19.2 \
		quote-1.0.45 \
		rayon-1.11.0 \
		rayon-core-1.13.0 \
		redox_syscall-0.5.18 \
		roots-0.0.6 \
		rustversion-1.0.22 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.2.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		smallvec-1.15.1 \
		strsim-0.8.0 \
		syn-1.0.109 \
		syn-2.0.117 \
		target-lexicon-0.12.16 \
		textwrap-0.11.0 \
		tiff-0.6.1 \
		unicode-ident-1.0.24 \
		unicode-width-0.1.14 \
		unindent-0.1.11 \
		vec_map-0.8.2 \
		visioncortex-0.8.10 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.114 \
		wasm-bindgen-macro-0.2.114 \
		wasm-bindgen-macro-support-0.2.114 \
		wasm-bindgen-shared-0.2.114 \
		web-sys-0.3.91 \
		weezl-0.1.12 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		zmij-1.0.21

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
