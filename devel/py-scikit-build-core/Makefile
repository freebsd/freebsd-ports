PORTNAME=	scikit-build-core
DISTVERSION=	1.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build backend for CMake based projects
WWW=		https://scikit-build-core.readthedocs.io/en/latest/ \
		https://github.com/scikit-build/scikit-build-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.12.0:devel/py-pathspec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0.8:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=22.2.0:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>0:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.8:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=23:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.11:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subprocess>=1.5:devel/py-pytest-subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate-pyproject>0:devel/py-validate-pyproject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.20:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		git:devel/git \
		ninja>0:devel/ninja

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# setuptools integration tests fail with the setuptools version in the tree (pydantic deprecation warnings escalate to errors)
TEST_ARGS=	--disable-plugin-autoload -p pytest_subprocess.fixtures \
		--ignore=tests/test_setuptools_abi3.py --ignore=tests/test_setuptools_pep517.py

NO_ARCH=	yes

# tests as of 1.1.2: 1205 passed, 8 skipped in 545.72s (0:09:05)

.include <bsd.port.mk>
