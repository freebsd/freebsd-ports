PORTNAME=	pydantic
DISTVERSION=	1.10.27
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data validation and settings management using python 3.6 type hinting
WWW=		https://github.com/samuelcolvin/pydantic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.79.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	distutils cython autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p pytest_mock -p pytest_timeout \
		-W ignore::pytest.PytestRemovedIn10Warning \
		--ignore=tests/mypy --deselect tests/test_validators.py::test_assert_raises_validation_error # mypy tests need old mypy, one test depends on pytest assertion message format

# tests as of 1.10.27: 2562 passed, 11 skipped, 1 deselected in 6.18s

.include <bsd.port.mk>
