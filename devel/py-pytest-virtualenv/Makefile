PORTNAME=	pytest-virtualenv
PORTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtualenv fixture for py.test

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=0:devel/py-setuptools-git@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-fixture-config>0:devel/py-pytest-fixture-config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-shutil>0:devel/py-pytest-shutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.4.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR}

USES=		python:3.6+

USE_PYTHON=	autoplist concurrent distutils

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs)

.include <bsd.port.mk>
