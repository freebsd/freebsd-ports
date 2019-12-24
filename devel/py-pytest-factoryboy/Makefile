# $FreeBSD$

PORTNAME=	pytest-factoryboy
PORTVERSION=	2.0.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Factory approach to testing with the dependency injection

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inflection>=0:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}factory-boy>=0:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # tests not shiped with sdist
GH_ACCOUNT=	pytest-dev
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
