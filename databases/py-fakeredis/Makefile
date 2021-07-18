PORTNAME=	fakeredis
PORTVERSION=	1.5.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake version of databases/py-redis for unit testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0<3.6:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.1.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest<5.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov<3.0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOREDIS LUA
AIOREDIS_DESC=	Asyncio redis support
LUA_DESC=	Lua support

AIOREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioredis>=0<2:databases/py-aioredis@${PY_FLAVOR}
LUA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lupa>=0:lang/py-lupa@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test_fakeredis.py

.include <bsd.port.mk>
