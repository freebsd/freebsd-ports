PORTNAME=	zarr
DISTVERSION=	3.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of chunked, compressed, N-dimensional arrays for Python
WWW=		https://zarr.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.29.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}donfig>=0.8:devel/py-donfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.5:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.19:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numcodecs>=0.16.6:misc/py-numcodecs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>0:textproc/py-numpydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>0:devel/py-uv@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${WRKSRC}/src
TEST_ARGS=	--disable-plugin-autoload -p pytest_asyncio.plugin -p hypothesis -p pytest_benchmark.plugin --ignore ${WRKSRC}/tests/test_regression

# tests as of 3.4.2: 12460 passed, 1272 skipped, 4 xfailed in 805.09s (0:13:25)

.include <bsd.port.mk>
