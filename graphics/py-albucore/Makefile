PORTNAME=	albucore
DISTVERSION=	0.0.22
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance image processing library
WWW=		https://github.com/albumentations-team/albucore

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}simsimd>=5.9.2:devel/py-simsimd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringzilla>=3.10.4:devel/py-stringzilla@${PY_FLAVOR} \
		opencv>0:graphics/opencv
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	albumentations-team

NO_ARCH=	yes

# tests as of 0.0.22: 721 passed in 12.46s

.include <bsd.port.mk>
