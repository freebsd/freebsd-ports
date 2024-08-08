PORTNAME=	peewee_migrate
DISTVERSION=	1.13.0
CATEGORIES=	databases devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple migration engine for Peewee
WWW=		https://github.com/klen/peewee_migrate

LICENSE=	BSD3CLAUSE

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>=0:databases/py-peewee@${PY_FLAVOR}
BUILD_DEPENDS=	${MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # tests not shipped with sdist, https://github.com/klen/peewee_migrate/issues/236
GH_ACCOUNT=	klen
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
