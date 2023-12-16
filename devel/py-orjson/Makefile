PORTNAME=	orjson
PORTVERSION=	3.9.10
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Fast, correct JSON library for Python
WWW=		https://pypi.org/project/orjson/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pendulum>0:devel/py-pendulum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR}

USES=		cargo python
USE_GITHUB=	yes
GH_ACCOUNT=	ijl
USE_PYTHON=	autoplist concurrent cython pep517 pytest

CARGO_CRATES=	ahash-0.8.6 \
		arrayvec-0.7.4 \
		associative-cache-2.0.0 \
		autocfg-1.1.0 \
		beef-0.5.2 \
		bytecount-0.6.7 \
		castaway-0.2.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		chrono-0.4.31 \
		compact_str-0.7.1 \
		encoding_rs-0.8.33 \
		itoa-1.0.9 \
		itoap-1.0.1 \
		libc-0.2.149 \
		libm-0.2.8 \
		no-panic-0.1.26 \
		num-traits-0.2.17 \
		once_cell-1.18.0 \
		packed_simd-0.3.9 \
		proc-macro2-1.0.69 \
		pyo3-build-config-0.20.0 \
		pyo3-ffi-0.20.0 \
		quote-1.0.33 \
		rustversion-1.0.14 \
		ryu-1.0.15 \
		serde-1.0.190 \
		serde_derive-1.0.190 \
		serde_json-1.0.107 \
		simdutf8-0.1.4 \
		smallvec-1.11.1 \
		static_assertions-1.1.0 \
		syn-2.0.38 \
		target-lexicon-0.12.12 \
		unicode-ident-1.0.12 \
		version_check-0.9.4 \
		zerocopy-0.7.15 \
		zerocopy-derive-0.7.15

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
