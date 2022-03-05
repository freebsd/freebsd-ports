PORTNAME=	ormar
DISTVERSION=	0.10.25
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple async ORM with fastapi in mind and pydantic validation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}databases>=0.3.2,<0.6.0:databases/py-databases@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.6.1,<1.8.3:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.0:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

OPTIONS_DEFINE=			CRYPTO
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=		SQLITE
DATABASES_DESC=			Database Support

CRYPTO_DESC=	Support for password encryption

CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}
SQLITE_USES=		sqlite
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}
MYSQL_USES=		mysql
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}
PGSQL_USES=		pgsql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asyncpg>0:databases/py-asyncpg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}

# Tests require newer pytest
# do-test:
	# cd ${WRKSRC} && ${SETENV} ${TEST_ENV} TEST_DATABASE_URLS="sqlite:///testsuite" ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
