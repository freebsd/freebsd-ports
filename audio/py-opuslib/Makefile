PORTNAME=	opuslib-next
DISTVERSION=	1.1.6
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to the libopus, IETF low-delay audio codec
WWW=		https://github.com/kalicyh/opuslib-next

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/lib/libopus.so:audio/opus
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pyproject

NO_ARCH=	yes

TEST_TARGET=	test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
