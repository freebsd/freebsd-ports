PORTNAME=	fakeredis
PORTVERSION=	1.8.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake version of databases/py-redis for unit testing

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0<4.3.1:databases/py-redis@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0<4.4:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16<2.0.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.3.0<3.0.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioredis>=1.3.1<3.0.0:databases/py-aioredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lupa>=1.13<2.0:lang/py-lupa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOREDIS LUA
AIOREDIS_DESC=	Asyncio redis support
LUA_DESC=	Lua support

AIOREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioredis>=1.3.1<3.0.0:databases/py-aioredis@${PY_FLAVOR}
LUA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lupa>=1.13<2.0:lang/py-lupa@${PY_FLAVOR}

.include <bsd.port.mk>
