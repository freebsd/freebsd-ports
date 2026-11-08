PORTNAME=	curl-cffi
PORTVERSION=	0.16.3
CATEGORIES=	ftp python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	libcurl ffi bindings for Python
WWW=		https://curl-cffi.readthedocs.io/en/latest/ \
		https://github.com/lexiforest/curl_cffi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=2.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcurl-impersonate.so:ftp/curl-impersonate
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2024.2.2:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=2.0.0:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.3.2:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=46.0.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}litestar>=2.19.0:www/py-litestar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proxy.py>=2.4.3:www/py-proxy.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.23.6:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-trio>=0.8.0:devel/py-pytest-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.9:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.25.0:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=1.1.0:security/py-trustme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.29.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}

USES=		dos2unix python ssl
DOS2UNIX_FILES=	tests/unittest/test_async_websockets.py
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
TEST_WRKSRC=	${WRKSRC}/tests/unittest
TEST_ARGS=	--disable-plugin-autoload -p pytest_asyncio.plugin -p pytest_trio.plugin \
		--ignore=test_upload.py
# test_upload.py needs assets/ files that are not included in the PyPI
# sdist (only present in the upstream git repository)

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

# tests as of 0.16.3: 531 passed, 19 skipped, 34 warnings in 27.88s (presence of py312-orjson causes another 1 test to fail)

.include <bsd.port.mk>
