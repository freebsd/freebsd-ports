PORTNAME=	traitlets
DISTVERSION=	5.16.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Configuration system for Python applications
WWW=		https://github.com/ipython/traitlets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.5:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=3.0.3:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=2.0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy-testing>0:devel/py-pytest-mypy-testing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# The mypy typing tests expect mypy <1.19 output formatting, but ports ships
# mypy 2.x; disable the pytest-mypy-testing plugin so the rest of the suite runs.
# Disable pytest-randomly as one test is sensitive to test ordering.
TEST_ARGS=	-p no:mypy-testing -p no:randomly

# tests as of 5.16.1: 581 passed in 8.99s

.include <bsd.port.mk>
