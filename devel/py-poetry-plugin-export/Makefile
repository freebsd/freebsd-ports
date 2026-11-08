PORTNAME=	poetry-plugin-export
DISTVERSION=	1.10.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Poetry plugin to export the dependencies to various formats
WWW=		https://python-poetry.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>=2.1.0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=2.1.0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.4:textproc/py-tomlkit@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>=1.18.1:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>0:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}
# devel/py-poetry is a circular dependency because poetry also depends on poetry-plugin-export. devel/py-poetry was moved to TEST_DEPENDS.

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_cov.plugin \
		-p pytest_mock \
		-p pytest_randomly \
		-p xdist.plugin

# tests as of 1.10.1: 178 passed in 21.88s

.include <bsd.port.mk>
