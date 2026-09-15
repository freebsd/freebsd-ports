PORTNAME=	ccxt
DISTVERSION=	4.5.78
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cryptocurrency trading API with support for 100+ exchanges
WWW=		https://github.com/ccxt/ccxt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohappyeyeballs>=2.7.1:net/py-aiohappyeyeballs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-fast-zlib>=0.3.0:www/py-aiohttp-fast-zlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.14.3:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosignal>=1.4.0:devel/py-aiosignal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=26.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2026.6.17:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=2.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.7:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coincurve>=21.0.0:security/py-coincurve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozenlist>=1.8.0:devel/py-frozenlist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.18:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=6.7.1:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.11.9:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}propcache>=0.5.2:devel/py-propcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>=2.23:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.16.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.7.0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.22.1:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.20:www/py-yarl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zlib-ng>=1.0.0:archivers/py-zlib-ng@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist cryptography pytest # see https://github.com/ccxt/ccxt/issues/29383

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/python/ccxt/test/base
TEST_ARGS=	--confcutdir=. \
		-p pytest_asyncio -o asyncio_mode=auto \
		-p no:relaxed -p no:ruff -p no:mypy -p no:cov \
		--ignore=language_specific/test_throttler_performance.py

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ccxt -type d \( -name '.benchmarks' -o -name '.pytest_cache' \) -exec ${RM} -rf {} + 2>/dev/null || true

post-extract: # workaround for https://github.com/ccxt/ccxt/issues/16220
	@${TOUCH} ${WRKSRC}/README.md

# tests as of 4.5.78: 102 passed, 6 warnings in 19.00s

.include <bsd.port.mk>
