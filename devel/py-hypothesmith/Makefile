PORTNAME=	hypothesmith
PORTVERSION=	0.1.8
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hypothesis strategies for generating Python programs

LICENSE=	MPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark-parser>=0:devel/py-lark-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=0:devel/py-libcst@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/tox-${PYTHON_VER} --sitepackages

.include <bsd.port.mk>
