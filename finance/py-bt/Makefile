PORTNAME=	bt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible backtesting framework to test quantitative trading strategies
WWW=		http://pmorissette.github.io/bt/ \
		https://github.com/pmorissette/bt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ffn>=1.1.2:finance/py-ffn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyprind>=2.11:misc/py-pyprind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pmorissette

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bt/core${PYTHON_TAG}.so

do-test: # needed to prevent failures due to -k and -r arguments
	@cd ${TEST_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest tests/ -rs -v -o addopts= ${TEST_ARGS:NDESTDIR=*}

# tests as of 1.1.3: see https://github.com/pmorissette/bt/issues/499
# Results (103.72s):
#         1 failed
#       488 passed
#       149 warnings

.include <bsd.port.mk>
