PORTNAME=	enlighten
DISTVERSION=	1.14.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Console progress bar module for Python
WWW=		https://github.com/Rockhopper-Technologies/enlighten

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blessed>=1.17.7:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prefixed>=0.3.2:devel/py-prefixed@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

PYTEST_ARGS=	-p no:ruff -p no:cov

NO_ARCH=	yes

# tests as of 1.14.1: 145 passed, 1 skipped in 57.67s

.include <bsd.port.mk>
