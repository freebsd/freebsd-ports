PORTNAME=	ormsgpack
DISTVERSION=	1.10.0
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
		${PYTHON_PKGNAMEPREFIX}pydantic>0:devel/py-pydantic@${PY_FLAVOR} \
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
		autocfg-1.4.0 \
		bytecount-0.6.8 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		chrono-0.4.41 \
		crunchy-0.2.3 \
		half-2.6.0 \
		itoa-1.0.15 \
		libc-0.2.171 \
		memoffset-0.9.1 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		portable-atomic-1.11.0 \
		proc-macro2-1.0.94 \
		pyo3-0.25.0 \
		pyo3-build-config-0.25.0 \
		pyo3-ffi-0.25.0 \
		quote-1.0.40 \
		serde-1.0.219 \
		serde_bytes-0.11.17 \
		serde_derive-1.0.219 \
		simdutf8-0.1.5 \
		smallvec-1.15.0 \
		syn-2.0.100 \
		target-lexicon-0.13.2 \
		unicode-ident-1.0.18 \
		version_check-0.9.5 \
		zerocopy-0.8.25 \
		zerocopy-derive-0.8.25

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

# tests as of 1.10.0: 8 failed, 504 passed, 1 warning in 7.64s, see https://github.com/aviramha/ormsgpack/issues/411

.include <bsd.port.mk>
