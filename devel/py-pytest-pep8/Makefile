PORTNAME=	pytest-pep8
PORTVERSION=	1.0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Pytest plugin to check PEP8 requirements

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cache>=0:devel/py-pytest-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8>=1.3:devel/pep8@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		-k 'not test_strict \
		and not test_ok_verbose \
		and not test_mtime_caching \
		and not test_w293w292'

.include <bsd.port.mk>
