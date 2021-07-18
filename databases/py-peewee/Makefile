# Created by: Matthias Petermann <matthias@petermann-it.de>

PORTNAME=	peewee
DISTVERSION=	3.14.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Small, expressive Python ORM

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=		SQLITE PGSQL
OPTIONS_DEFAULT=	SQLITE

USES=			localbase:ldflags python:3.6+ sqlite
USE_PYTHON=		distutils cython autoplist concurrent

SQLITE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
PGSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.1:databases/py-psycopg2@${PY_FLAVOR}

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=	--include-dirs=${LOCALBASE}/include \
			--library-dirs=${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playhouse/*.so

do-test:
	${PYTHON_CMD} ${WRKSRC}/runtests.py

.include <bsd.port.mk>
