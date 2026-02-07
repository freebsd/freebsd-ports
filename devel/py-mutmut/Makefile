PORTNAME=	mutmut
DISTVERSION=	3.3.1
CATEGORIES=	devel
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mutation testing for Python 3
WWW=		https://mutmut.readthedocs.io/en/latest/ \
		https://github.com/boxed/mutmut

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.8:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=1.7.0:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>0:textproc/py-textual@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hammett>0:devel/py-hammett@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whatthepatch>=0.0.6:textproc/py-whatthepatch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 2 tests fail because they require the fixture 'testdata' which is only for Python-3.10+

USE_GITHUB=	yes
GH_ACCOUNT=	boxed

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

# tests as of 3.3.1: 170 passed, 1 skipped, 18 warnings in 3.77s

.include <bsd.port.mk>
