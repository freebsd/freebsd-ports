PORTNAME=	flake8-builtins
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flake8_builtins-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Check for python builtins being used as variables or parameters
WWW=		https://pypi.org/project/flake8-builtins/ \
		https://github.com/gforcada/flake8-builtins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/py.test-${PYTHON_VER} run_tests.py

.include <bsd.port.mk>
