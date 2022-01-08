PORTNAME=	databases
DISTVERSION=	0.5.5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Async database support for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiopg>0:databases/py-aiopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncpg>0:databases/py-asyncpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

# USE_GITHUB=	yes
# GH_ACCOUNT=	encode

NO_ARCH=	yes

OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=		SQLITE
DATABASES_DESC=			Database Support

MYSQL_USES=		mysql
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR}
PGSQL_USES=		pgsql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiopg>0:databases/py-aiopg@${PY_FLAVOR}
SQLITE_USES=		sqlite
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}

# do-test:
# 	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} TEST_DATABASE_URLS="sqlite:///testsuite" ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
