PORTNAME=	custodian
DISTVERSION=	2023.6.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple JIT job management framework in Python
WWW=		https://github.com/materialsproject/custodian

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}monty>=2022.9.9:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.4:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.21:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.14.0:devel/py-sentry-sdk@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=6.5.0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coveralls>=3.3.1:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>=0:devel/py-pydocstyle@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=1.7:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>0:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} # from requirements-ci.txt

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
