PORTNAME=	pytest-metadata
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_metadata-${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Pytest plugin for test session metadata
WWW=		https://github.com/pytest-dev/pytest-metadata

LICENSE=	MPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.0.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=22.1.0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=4.0.1:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=3.24.5:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=2.17.0:devel/py-pre-commit@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
