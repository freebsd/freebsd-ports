PORTNAME=	hypothesmith
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hypothesis strategies for generating Python programs

LICENSE=	MPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark-parser>=0:devel/py-lark-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=0:devel/py-libcst@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>=0:textproc/py-parso@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}"

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -o addopts= -v -rs

.include <bsd.port.mk>
