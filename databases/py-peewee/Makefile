PORTNAME=	peewee
DISTVERSION=	4.0.8
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Small, expressive Python ORM
WWW=		https://peewee.readthedocs.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=			localbase:ldflags python sqlite
USE_PYTHON=		autoplist concurrent cython distutils
PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=	--include-dirs=${LOCALBASE}/include \
			--library-dirs=${LOCALBASE}/lib

OPTIONS_DEFINE=		PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

PGSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.1:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

post-extract:
	@${RM} ${WRKSRC}/playhouse/*.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playhouse/*.so

do-test:
	${PYTHON_CMD} ${WRKSRC}/runtests.py

.include <bsd.port.mk>
