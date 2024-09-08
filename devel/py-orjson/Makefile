PORTNAME=	orjson
PORTVERSION=	3.10.6
PORTREVISION=	1
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
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

CARGO_CRATES=	arrayvec-0.7.4 \
		associative-cache-2.0.0 \
		autocfg-1.3.0 \
		beef-0.5.2 \
		bytecount-0.6.8 \
		castaway-0.2.2 \
		cc-1.0.104 \
		cfg-if-1.0.0 \
		chrono-0.4.34 \
		compact_str-0.7.1 \
		crunchy-0.2.2 \
		encoding_rs-0.8.34 \
		gimli-0.30.0 \
		half-2.4.1 \
		itoa-1.0.11 \
		itoap-1.0.1 \
		libc-0.2.155 \
		no-panic-0.1.30 \
		num-traits-0.2.19 \
		once_cell-1.19.0 \
		proc-macro2-1.0.86 \
		pyo3-build-config-0.22.0 \
		pyo3-ffi-0.22.0 \
		quote-1.0.36 \
		rustversion-1.0.17 \
		ryu-1.0.18 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_json-1.0.120 \
		simdutf8-0.1.4 \
		smallvec-1.13.2 \
		static_assertions-1.1.0 \
		syn-2.0.68 \
		target-lexicon-0.12.14 \
		unicode-ident-1.0.12 \
		unwinding-0.2.2 \
		version_check-0.9.4 \
		xxhash-rust-0.8.10

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
