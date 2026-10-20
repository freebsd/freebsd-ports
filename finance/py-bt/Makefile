PORTNAME=	bt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-cython>0:devel/py-hatch-cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ffn>=1.1.2:finance/py-ffn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyprind>=2.11:misc/py-pyprind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pmorissette

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bt/core${PYTHON_TAG}.so

do-test: # needed to prevent failures due to -k and -r arguments
	@cd ${TEST_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest tests/ -rs -v -o addopts= ${TEST_ARGS:NDESTDIR=*}

# tests as of 1.4.1: 799 passed, 13 warnings in 64.44s (0:01:04)

.include <bsd.port.mk>
