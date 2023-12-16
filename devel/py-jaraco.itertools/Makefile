PORTNAME=	jaraco.itertools
PORTVERSION=	6.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for working with iterables
WWW=		https://github.com/jaraco/jaraco.itertools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=56:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.1:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inflect>=0:devel/py-inflect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=4.0.0:devel/py-more-itertools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-black>=0.3.7:devel/py-pytest-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-checkdocs>=2.4:devel/py-pytest-checkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-enabler>=1.0.1:devel/py-pytest-enabler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>=0:devel/py-pytest-mypy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
