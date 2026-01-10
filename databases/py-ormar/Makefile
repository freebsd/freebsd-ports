PORTNAME=	ormar
DISTVERSION=	0.21.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple async ORM with fastapi in mind and pydantic validation
WWW=		https://github.com/collerek/ormar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}databases>=0.3.2:databases/py-databases@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>=0:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncpg>=0:databases/py-asyncpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Faker>=0:devel/py-Faker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=0:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	collerek
USE_PYTHON=	autoplist concurrent cryptography pep517 pytest
PYTEST_BROKEN_TESTS=	test_benchmark_aggregate test_benchmark_bulk_create \
			test_benchmark_bulk_update test_benchmark_create \
			test_benchmark_delete test_benchmark_get \
			test_benchmark_init test_benchmark_iterate \
			test_benchmark_save test_benchmark_update \
			test_benchmark_values

TEST_ENV=	PYTHONPATH=${WRKSRC}

NO_ARCH=	yes

OPTIONS_DEFINE=			CRYPTO
OPTIONS_DEFAULT=		SQLITE
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	MYSQL PGSQL SQLITE

CRYPTO_DESC=		Support for password encryption
DATABASES_DESC=		Database Support

CRYPTO_USE=		PYTHON=cryptography
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomysql>0:databases/py-aiomysql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}
MYSQL_USES=		mysql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asyncpg>0:databases/py-asyncpg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
PGSQL_USES=		pgsql
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}
SQLITE_USES=		sqlite

.include <bsd.port.mk>
