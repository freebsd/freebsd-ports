PORTNAME=	fakeredis
PORTVERSION=	2.20.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake version of databases/py-redis for unit testing
WWW=		https://github.com/cunla/fakeredis-py

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=4:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2<3:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpath-ng>=1.5<2:devel/py-jsonpath-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lupa>=1.14<2:lang/py-lupa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	JSON LUA
LUA_DESC=	Lua support

JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpath-ng>=1.5<2:devel/py-jsonpath-ng@${PY_FLAVOR}
LUA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lupa>=1.14<3.0:lang/py-lupa@${PY_FLAVOR}

.include <bsd.port.mk>
