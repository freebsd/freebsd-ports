PORTNAME=	milc
DISTVERSION=	1.4.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Opinionated, batteries-included Python 3 CLI framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}halo>=0:misc/py-halo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spinners>=0:misc/py-spinners@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose2>=0:devel/py-nose2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	clueboard
USE_PYTHON=	autoplist distutils

# There is no need to run yapf during tests
# because it only checks code formatting.
BINARY_ALIAS=	python3=${PYTHON_CMD} yapf=true

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./ci_tests)

.include <bsd.port.mk>
