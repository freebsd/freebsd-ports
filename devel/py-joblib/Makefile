PORTNAME=	joblib
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lightweight pipelining using Python functions as jobs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4>0:devel/py-pytest4@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	PYTHON_PATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# Skip some tests as they're known to fail. See also:
#
# https://github.com/joblib/joblib/issues/57
# https://github.com/joblib/joblib/issues/1115
# https://github.com/joblib/joblib/issues/1141
do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		-k 'not test_disk_used and not defined_in_jupyter'

.include <bsd.port.mk>
