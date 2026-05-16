PORTNAME=	cachebox
DISTVERSION=	5.2.3
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

CARGO_CRATES=	autocfg-1.4.0 \
		bitflags-2.9.0 \
		cc-1.2.40 \
		cfg-if-1.0.3 \
		fastrand-2.3.0 \
		find-msvc-tools-0.1.4 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		indoc-2.0.6 \
		libc-0.2.171 \
		libmimalloc-sys-0.1.44 \
		lock_api-0.4.14 \
		memoffset-0.9.1 \
		mimalloc-0.1.48 \
		once_cell-1.21.3 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		portable-atomic-1.11.0 \
		proc-macro2-1.0.94 \
		pyo3-0.27.1 \
		pyo3-build-config-0.27.1 \
		pyo3-ffi-0.27.1 \
		pyo3-macros-0.27.1 \
		pyo3-macros-backend-0.27.1 \
		python3-dll-a-0.2.14 \
		quote-1.0.40 \
		redox_syscall-0.5.10 \
		scopeguard-1.2.0 \
		shlex-1.3.0 \
		smallvec-1.14.0 \
		syn-2.0.100 \
		target-lexicon-0.13.2 \
		unicode-ident-1.0.18 \
		unindent-0.2.4 \
		windows-link-0.2.0
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

pre-test:
	${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cachebox/_core*.so \
	    ${WRKSRC}/python/cachebox/

do-test:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-p no:checkdocs -p no:xdist -v -rs -o addopts= \
		-k "not test_eq_implemetation" \
		--ignore=cargo-crates --ignore=python/cachebox python/tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

# the tes python/tests/test_caches.py::TestLFUCache::test_update_sizeof_error_preserves_entry hangs, see https://github.com/awolverp/cachebox/issues/52

.include <bsd.port.mk>
