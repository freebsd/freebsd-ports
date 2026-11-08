PORTNAME=	ormsgpack
DISTVERSION=	1.13.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Python msgpack library supporting dataclasses, datetimes, numpy
WWW=		https://github.com/aviramha/ormsgpack

LICENSE=		APACHE20 MIT
LICENSE_COMB=		dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0:devel/py-maturin@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		gmake:devel/gmake
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pendulum>0:devel/py-pendulum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-python-dateutil>0:devel/py-types-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>0:devel/py-tzdata@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aviramha

CARGO_CRATES=	ahash-0.8.12 \
		autocfg-1.5.0 \
		cfg-if-1.0.4 \
		chrono-0.4.45 \
		crunchy-0.2.4 \
		half-2.7.1 \
		heck-0.5.0 \
		itoa-1.0.18 \
		libc-0.2.180 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		portable-atomic-1.13.0 \
		proc-macro2-1.0.105 \
		pyo3-0.30.1 \
		pyo3-build-config-0.30.1 \
		pyo3-ffi-0.30.1 \
		pyo3-macros-0.30.1 \
		pyo3-macros-backend-0.30.1 \
		quote-1.0.43 \
		serde-1.0.229 \
		serde_bytes-0.11.19 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		simdutf8-0.1.5 \
		smallvec-1.16.2 \
		syn-2.0.114 \
		syn-3.0.2 \
		target-lexicon-0.13.4 \
		unicode-ident-1.0.22 \
		version_check-0.9.5 \
		zerocopy-0.8.33 \
		zerocopy-derive-0.8.33

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

# tests as of 1.13.0: 623 passed in 0.61s

.include <bsd.port.mk>
