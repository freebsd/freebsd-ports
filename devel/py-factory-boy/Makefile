PORTNAME=	factory-boy
DISTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	factory_boy-${DISTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Create comlex objects for testing purposes
WWW=		https://github.com/FactoryBoy/factory_boy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Faker>=0:devel/py-Faker@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=0:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0:databases/py-mongoengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-utils>=0:databases/py-sqlalchemy-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

PYTEST_IGNORED_TESTS=	test_mongoengine test_version
TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
