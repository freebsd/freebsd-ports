# $FreeBSD$

PORTNAME=	milc
DISTVERSION=	1.1.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Opinionated, batteries-included Python 3 CLI framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose2>=0:devel/py-nose2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>=0:textproc/py-yapf@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	clueboard
USE_PYTHON=	autoplist distutils

BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./ci_tests)

.include <bsd.port.mk>
