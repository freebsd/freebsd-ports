PORTNAME=	ccxt
DISTVERSION=	4.5.70
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.14.1:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2026.6.17:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.34.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.16.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.24.2:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist cryptography pytest # see https://github.com/ccxt/ccxt/issues/29383

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/python/ccxt/test
TEST_ARGS=	-o asyncio_mode=auto \
		-p no:relaxed \
		-k 'not trio' \
		--ignore=exchange \
		--ignore=base/language_specific/test_throttler_performance.py

post-extract: # workaround for https://github.com/ccxt/ccxt/issues/16220
	@${TOUCH} ${WRKSRC}/README.md

# tests as of 4.5.70: 92 passed, 2 warnings in 25.39s

.include <bsd.port.mk>
