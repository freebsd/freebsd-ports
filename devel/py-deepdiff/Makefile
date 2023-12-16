PORTNAME=	deepdiff
DISTVERSION=	6.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep difference and search of any Python object/data
WWW=		https://github.com/seperman/deepdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ordered-set>=4.0.2:devel/py-ordered-set@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-PyYAML>=0:devel/py-types-PyYAML@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test: # some tests fail, see https://github.com/seperman/deepdiff/issues/323
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
