PORTNAME=	natsort
DISTVERSION=	8.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Natural sorting for python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=3.8.0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>0:devel/py-semver@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
