PORTNAME=	deepdiff
DISTVERSION=	9.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep difference and search of any Python object/data
WWW=		https://github.com/qlustered/deepdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachebox>=5.2,<6:devel/py-cachebox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orderly-set>=5.5.0:devel/py-orderly-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>0:misc/py-polars@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>0:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		cpe python shebangfix
CPE_VENDOR=	qluster
USE_PYTHON=	pep517 concurrent autoplist pytest

SHEBANG_FILES=	deepdiff/diff.py

NO_ARCH=	yes

do-test: # 3 tests fail, see https://github.com/seperman/deepdiff/issues/482
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

# tests as of 9.0.0: 1 passed in 2.91s

.include <bsd.port.mk>
