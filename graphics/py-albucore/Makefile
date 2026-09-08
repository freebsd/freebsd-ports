PORTNAME=	albucore
DISTVERSION=	0.2.18
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance image processing library
WWW=		https://github.com/albumentations-team/albucore

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numkong>=7.8.0:devel/py-numkong@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringzilla>=5.1.2:devel/py-stringzilla@${PY_FLAVOR} \
		opencv>0:graphics/opencv
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	albumentations-team

NO_ARCH=	yes

# tests as of 0.2.18: 2440 passed

.include <bsd.port.mk>
