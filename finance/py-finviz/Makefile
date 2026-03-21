PORTNAME=	finviz
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unofficial API for FinViz.com
WWW=		https://github.com/mariostoev/finviz

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>=1.2.0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.0.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.64.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
