PORTNAME=	ormar
DISTVERSION=	0.12.2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple async ORM with fastapi in mind and pydantic validation
WWW=		https://github.com/collerek/ormar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}databases>=0.3.2,<0.9.0:databases/py-databases@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.6.1,<1.11.0,1:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.0:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=0:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncpg>=0:databases/py-asyncpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR}

USES=		python
USE_GITHUB=	YES
USE_PYTHON=	autoplist concurrent pep517 pytest
GH_ACCOUNT=	collerek
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR}

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

OPTIONS_DEFINE=			CRYPTO
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=		SQLITE
DATABASES_DESC=			Database Support

CRYPTO_DESC=		Support for password encryption
CRYPTO_USE=		PYTHON=cryptography
SQLITE_USES=		sqlite
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}
MYSQL_USES=		mysql
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}
PGSQL_USES=		pgsql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asyncpg>0:databases/py-asyncpg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}

.include <bsd.port.mk>
