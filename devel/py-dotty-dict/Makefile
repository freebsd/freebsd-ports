# $FreeBSD$

PORTNAME=	dotty-dict
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Dictionary wrapper for quick access to deeply nested keys

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
# Use GitHub instead of CHEESESHOP to get the test files.
USE_GITHUB=	yes
GH_ACCOUNT=	pawelzny
GH_PROJECT=	${PORTNAME:S/-/_/}
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
# Call the pytest module directly instead of using the official "test"
# make target in order to avoid calling pipenv.
	(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
