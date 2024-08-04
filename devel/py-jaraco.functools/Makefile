PORTNAME=	jaraco.functools
PORTVERSION=	4.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jaraco_functools-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional functools for Python
WWW=		https://github.com/jaraco/jaraco.functools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}more-itertools>=2.7:devel/py-more-itertools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.classes>=0:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-checkdocs>=2.4:devel/py-pytest-checkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-enabler>=2.2:devel/py-pytest-enabler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>=0:devel/py-pytest-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-ruff>=0.2.1:devel/py-pytest-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
