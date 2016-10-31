# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	peewee
PORTVERSION=	2.8.5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Small, expressive Python ORM

LICENSE=	MIT

OPTIONS_DEFINE=		DOCS SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

USES=		python
USE_PYTHON=	autoplist distutils

SQLITE_BUILD_DEPENDS=	${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3
MYSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb
PGSQL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.1:databases/py-psycopg2

.include <bsd.port.mk>
