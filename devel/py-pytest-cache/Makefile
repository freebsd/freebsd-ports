PORTNAME=	pytest-cache
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pytest plugin with mechanisms for caching across test runs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pytest4-cache

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.2:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>=1.2:sysutils/py-execnet@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP}
TEST_TARGET=	test

.include <bsd.port.mk>
