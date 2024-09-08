PORTNAME=	mutmut
DISTVERSION=	2.5.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mutation testing for Python 3
WWW=		https://mutmut.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glob2>0:devel/py-glob2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.8:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pony>0:databases/py-pony@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hammett>0:devel/py-hammett@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whatthepatch>=0.0.6:textproc/py-whatthepatch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 2 tests fail because they require the fixture 'testdata' which is only for Python-3.10+

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
