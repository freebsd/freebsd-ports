PORTNAME=	databases
DISTVERSION=	0.9.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Async database support for Python
WWW=		https://github.com/encode/databases

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiopg>0:databases/py-aiopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncmy>0:databases/py-asyncmy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncpg>0:databases/py-asyncpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	encode
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV+=	TEST_DATABASE_URLS="sqlite:///testsuite"

NO_ARCH=	yes

OPTIONS_DEFAULT=		SQLITE
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	MYSQL PGSQL SQLITE
DATABASES_DESC=			Database Support

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR}
MYSQL_USES=		mysql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiopg>0:databases/py-aiopg@${PY_FLAVOR}
PGSQL_USES=		pgsql
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}
SQLITE_USES=		sqlite

post-extract:
	${TOUCH} ${WRKSRC}/tests/__init__.py

.include <bsd.port.mk>
