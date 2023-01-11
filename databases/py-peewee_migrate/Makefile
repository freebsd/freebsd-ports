PORTNAME=	peewee_migrate
DISTVERSION=	1.6.2
CATEGORIES=	databases devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple migration engine for Peewee
WWW=		https://github.com/klen/peewee_migrate

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>=0:databases/py-peewee@${PY_FLAVOR}
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.7+
USE_GITHUB=	yes # tests not shipped with sdist
GH_ACCOUNT=	klen
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cached-property>=0:devel/py-cached-property@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
