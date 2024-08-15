PORTNAME=	asv
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	benchmarks python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Airspeed Velocity: A simple Python history benchmarking tool
WWW=		https://asv.readthedocs.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS:=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asv-runner>=0.1.0:benchmarks/py-asv-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json5>0:devel/py-json5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pympler>0:devel/py-pympler@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=10.0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		${PY_NUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>0:www/py-selenium@${PY_FLAVOR} \
		git:devel/git \
		${PYTHON_PKGNAMEPREFIX}hglib>0:devel/py-hglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpy2>0:math/py-rpy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

# failed because conda is not available
PYTEST_IGNORED_TESTS=	test_custom_commands \
			test_installed_commit_hash \
			test_install_success \
			test_install_env_matrix_values

.include <bsd.port.mk>
