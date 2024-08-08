PORTNAME=	pytest-checkdocs
PORTVERSION=	2.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_checkdocs-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check the README when running tests
WWW=		https://github.com/jaraco/pytest-checkdocs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.15,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.packaging>=9.5:devel/py-jaraco.packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-enabler>=2.2:devel/py-pytest-enabler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>=0:devel/py-pytest-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-ruff>=0.2.1:devel/py-pytest-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-docutils>=0:devel/py-types-docutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
