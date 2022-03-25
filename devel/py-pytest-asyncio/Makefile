PORTNAME=	pytest-asyncio
PORTVERSION=	0.18.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Py.test plugin providing fixtures and markers for asyncio

LICENSE=	APACHE20

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pytest4-asyncio

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flaky>=3.5.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=5.7.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-trio>=0.7.0:devel/py-pytest-trio@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
