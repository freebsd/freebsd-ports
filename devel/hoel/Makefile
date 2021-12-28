PORTNAME=	hoel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.14
CATEGORIES=	devel

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Database abstraction library written in C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

LIB_DEPENDS+=	libjansson.so:devel/jansson
LIB_DEPENDS+=	liborcania.so:devel/orcania

BUILD_DEPENDS+=	orcania>0:devel/orcania
BUILD_DEPENDS+=	yder>0:devel/yder

RUN_DEPENDS+=	jansson>0:devel/jansson
RUN_DEPENDS+=	yder>0:devel/yder

OPTIONS_DEFINE=	MARIADB PGSQL SQLITE3
OPTIONS_DEFAULT=	PGSQL

PGSQL_DESC=	Use PostgreSQL as backend
SQLITE3_DESC=	Use SQLite 3 as backend
MARIADB_DESC=	Use MariaDB as backend

MARIADB_USES=	mariadb
PGSQL_USES=	pgsql
SQLITE3_USES=	sqlite3

MARIADB_CMAKE_BOOL=	WITH_MARIADB
PGSQL_CMAKE_BOOL=	WITH_PGSQL
SQLITE3_CMAKE_BOOL=	WITH_SQLITE3

CMAKE_ARGS=	-DWITH_JOURNALD=off
# -DWITH_PGSQL=on
# -DWITH_SQLITE3=off
# -DWITH_MARIADB=off

.include <bsd.port.mk>
