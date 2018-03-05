# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	peewee
DISTVERSION=	3.1.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Small, expressive Python ORM

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=		SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

USES=			localbase python sqlite
USE_PYTHON=		distutils cython autoplist concurrent

SQLITE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}
MYSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb@${FLAVOR}
PGSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.1:databases/py-psycopg2@${FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playhouse/_speedups.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playhouse/_sqlite_ext.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playhouse/_sqlite_udf.so

.include <bsd.port.mk>
