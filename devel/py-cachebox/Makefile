PORTNAME=	cachebox
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fastest memoizing and caching Python library written in Rust
WWW=		https://github.com/awolverp/cachebox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8<2.0:devel/py-maturin@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517 pytest

CARGO_CRATES=	android_system_properties-0.1.5 \
		autocfg-1.5.1 \
		bitflags-2.11.1 \
		bumpalo-3.20.3 \
		cc-1.2.62 \
		cfg-if-1.0.4 \
		chrono-0.4.44 \
		core-foundation-sys-0.8.7 \
		fastrand-2.4.1 \
		find-msvc-tools-0.1.9 \
		futures-core-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		heck-0.5.0 \
		iana-time-zone-0.1.65 \
		iana-time-zone-haiku-0.1.2 \
		js-sys-0.3.99 \
		libc-0.2.186 \
		lock_api-0.4.14 \
		log-0.4.29 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		pin-project-lite-0.2.17 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		python3-dll-a-0.2.15 \
		quote-1.0.45 \
		redox_syscall-0.5.18 \
		rustversion-1.0.22 \
		scopeguard-1.2.0 \
		shlex-1.3.0 \
		slab-0.4.12 \
		smallvec-1.15.1 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		unicode-ident-1.0.24 \
		wasm-bindgen-0.2.122 \
		wasm-bindgen-macro-0.2.122 \
		wasm-bindgen-macro-support-0.2.122 \
		wasm-bindgen-shared-0.2.122 \
		windows-core-0.62.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV} RUSTC_BOOTSTRAP=1
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

pre-test:
	${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cachebox/_core*.so \
	    ${WRKSRC}/cachebox/

do-test:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-p no:checkdocs -p no:xdist -v -rs -o addopts= \
		--ignore=cargo-crates --ignore=cachebox tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

# tests as of 6.0.0: 923 passed, 6 skipped in 54.12s

.include <bsd.port.mk>
