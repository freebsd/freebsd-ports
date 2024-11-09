PORTNAME=	scikit-build
DISTVERSION=	0.18.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build system generator for Python C/C++/Fortran/Cython extensions
WWW=		https://scikit-build.readthedocs.io/en/latest/ \
		https://github.com/scikit-build/scikit-build

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.32.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}build>=0.7:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path.py>=11.5.0:devel/py-path.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10.4:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 tests fail, 4 errors, see https://github.com/scikit-build/scikit-build/issues/791

NO_ARCH=	yes

# tests 2 failed, 61 passed, 2 skipped, 4 warnings in 285.83s (0:04:45), see https://github.com/scikit-build/scikit-build/issues/1124

.include <bsd.port.mk>
