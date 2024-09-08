PORTNAME=	scikit-build-core
DISTVERSION=	0.10.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build backend for CMake based projects
WWW=		https://scikit-build-core.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYNUMPY} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.10.1:devel/py-pathspec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0.1:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=22.2.0:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.11:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.5:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subprocess>=1.5:devel/py-pytest-subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.20:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	pep517 autoplist pytest
# 3 tests fail, see https://github.com/scikit-build/scikit-build-core/issues/531

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
