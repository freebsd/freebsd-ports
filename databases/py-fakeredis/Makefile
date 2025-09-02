PORTNAME=	fakeredis
PORTVERSION=	2.30.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake version of databases/py-redis for unit testing
WWW=		https://github.com/cunla/fakeredis-py

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=4.3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2<3:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpath-ng>=1.5<2:devel/py-jsonpath-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lupa>=2.1<3.0:lang/py-lupa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	JSON LUA PROBABILISTIC VALKEY
LUA_DESC=		Lua support
PROBABILISTIC_DESC=	Probabilistic data structure support
VALKEY_DESC=		Valkey support

JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpath-ng>=1.5<2:devel/py-jsonpath-ng@${PY_FLAVOR}
LUA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lupa>=2.1<3.0:lang/py-lupa@${PY_FLAVOR}
PROBABILISTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyprobables>=0.6<1:math/py-pyprobables@${PY_FLAVOR}
VALKEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}valkey>=6:databases/py-valkey@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.7<5:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
